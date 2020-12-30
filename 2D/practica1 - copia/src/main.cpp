
#define LITE_GFX_IMPLEMENTATION

#include <litegfx.h>
#include <glfw3.h>
#include <iostream>
#include <sstream>
#include <Vec2.h>
#include <cmath>
#include <math.h>
#include <string>

using namespace std;

template <typename T>
std::string stringFromNumber(T val) {
	std::ostringstream stream;
	stream << std::fixed << val;
	return stream.str();
}


float squarePosX;
float squarePosY;
float circlePosX;
float circlePosY;

int main() {
	
	if (glfwInit())
	{
		double mousePosX;
		double mousePosY;
		//punteros
		double* pMouseX = &mousePosX;
		double* pMouseY = &mousePosY;

		//Resolución de ventana
		int windowWidth = 1024;
		int windowHeight = 768;

		float squareWidth = 50;
		float squareHeight = 50;

		GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Ventana Principal", nullptr, nullptr);
		glfwMakeContextCurrent(window);
		lgfx_setup2d(windowWidth, windowHeight);
		
		while (!glfwWindowShouldClose(window)) {

			float squarePosX = (float)*pMouseX - squareWidth / 2; //posición X centrada
			float squarePosY = (float)*pMouseY - squareHeight / 2; //poisición Y centrada

			float radius = 75.f; //distancia a la que el circulo orbita sobre el cuadrado
			float angle = (3.14f / 6) * glfwGetTime(); //32 grados

			float circlePosX = squarePosX + radius * sin(angle);  
			float circlePosY = squarePosY + radius * cos(angle); 
			//si se aplica el cos a X y el sin a Y se invierte la translación
			
			//fondo
			lgfx_clearcolorbuffer(1.f, 1.f, 1.f); 

			//cuadrado central
			lgfx_setcolor(1.0f, 0.0f, 0.0f, 1.f); 
			lgfx_drawrect(windowWidth /2 - squareWidth/2, windowHeight/2 - squareHeight/2, (float) squareWidth, (float) squareHeight);

			//cuadrado en ratón
			glfwGetCursorPos(window, pMouseX, pMouseY);

			lgfx_setcolor(0.7f, 0.2f, 0.7f, 1.f);
			lgfx_drawrect(squarePosX, squarePosY, (float)squareWidth, (float)squareHeight);

			lgfx_setcolor(0.f, 0.f, 1.f, 1.f);

			//círculo 
			lgfx_drawoval(circlePosX, circlePosY, 35.f, 35.f);

			//Datos

			//recogemos la posición de ambos para compararlos 
			Vec2 vecSquare = Vec2(squarePosX, squarePosY);
			Vec2 vecCircle = Vec2(circlePosX, circlePosY);

			std::string title = "Distancia: "
				+ stringFromNumber(vecSquare.distanceVec2(vecCircle))
				+ "-- Angulo: "
				+ stringFromNumber(vecSquare.angleVec2(vecCircle));
			
			glfwSetWindowTitle(window, title.c_str());

			//limpiar ventana
			glfwSwapBuffers(window);
			glfwPollEvents();
			
		} 
	}

	glfwTerminate();
	return 0;
}
