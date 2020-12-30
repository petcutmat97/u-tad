
#define LITE_GFX_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include <litegfx.h>
#include <glfw3.h>
#include <iostream>
#include <sstream>
#include <Vec2.h>
#include <cmath>
#include <math.h>
#include <string>
#include <stb_image.h>

using namespace std;

template <typename T>
std::string stringFromNumber(T val) {
	std::ostringstream stream;
	stream << std::fixed << val;
	return stream.str();
}


//Resolución de ventana
int windowWidth = 1024;
int windowHeight = 768;
int currentWindowWidth;
int currentWindowHeight;
//punteros
int* pCurrentWindowWidth = &currentWindowWidth;
int* pCurrentWindowHeight = &currentWindowHeight;

const char* wall = "data/wall.jpg";
const char* fire = "data/fire.png";
const char* grille = "data/grille.png";
const char* light = "data/light.png";

//textura pared
int wallWidth;
int wallHeight;
//punteros 
int* pWallWidth = &wallWidth;
int* pWallHeight = &wallHeight;

//textura fuego
int fireWidth;
int fireHeight;
//punteros 
int* pFireWidth = &fireWidth;
int* pFireHeight = &fireHeight;

//textura alambre
int grilleWidth;
int grilleHeight;
//punteros
int* pGrilleWidth = &grilleWidth;
int* pGrilleHeight = &grilleHeight;

//textura haz de luz
int lightWidth;
int lightHeight;
//punteros
int* pLightWidth = &lightWidth;
int* pLightHeight = &lightHeight;


bool isIncreasing = true;

//rotar llama de -10 a 10 pasando por 0
float angle = 0.0f;
float maxAngle = 30.f;
float minAngle = -30.f;

float rotAngle;
bool isRotPositive = true;

//cambiar el tamaño de la llama de 1.2 a 0.8
float maxFlameSize = 1.2f;
float minFlameSize = 0.8f;
float flameSize = 1.f;

int* bytesPerPixel; //canales

 
void loadBackground(ltex_t* _texture, float _textureWidth, float _textureHeight, float _WindowWidth, float _WindowHeight)
{
	float windowMaxSide = _WindowWidth > _WindowHeight ? _WindowWidth : _WindowHeight;
	float textureMaxSide = _textureWidth > _textureHeight ? _textureWidth : _textureHeight;
	int numTextures = (windowMaxSide / textureMaxSide) + 1; //encontrar el número mínimo de texturas por fila que cubra la ventana
	
	int i = 0; //filas

	while (numTextures >= i)
	{
		int j = 0; //elementos por fila
		while (j <= numTextures) //si llega al ultimo pasar a siguiente fila
		{
			ltex_draw(_texture, i * _textureWidth, j * _textureHeight);
			j++;
		}
		i++;
	}
}



ltex_t* loadTexture(const char* filename, int* _width, int* _height) {

	ltex_t* texture;

	unsigned char* data = stbi_load(filename, _width, _height, bytesPerPixel, 4); //load image
	
	int textureWidth = *_width;
	int textureHeight = *_height;

	if (data != nullptr)
	{
		texture = ltex_alloc(textureWidth, textureHeight, 0);
		if(texture != nullptr)
		{
			ltex_setpixels(texture, data);
		}
	}
	else {
		texture = nullptr;
	}
	return texture;
}


int main() {

	if (glfwInit())
	{
		double mousePosX;
		double mousePosY;
		//punteros
		double* pMouseX = &mousePosX;
		double* pMouseY = &mousePosY;

		GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Ventana Principal", nullptr, nullptr);
		glfwMakeContextCurrent(window);
		
		ltex_t* wallTexture = loadTexture(wall, pWallWidth, pWallHeight);
		ltex_t* fireTexture = loadTexture(fire, pFireWidth, pFireHeight);
		ltex_t* grilleTexture = loadTexture(grille, pGrilleWidth, pGrilleHeight);
		ltex_t* lightTexture = loadTexture(light, pLightWidth, pLightHeight);

		while(!glfwWindowShouldClose(window))
		{

			static float previous_seconds = static_cast<float>(glfwGetTime());
			float current_seconds = static_cast<float>(glfwGetTime());

			float elapsed_seconds = current_seconds - previous_seconds;
			previous_seconds = current_seconds;

			lgfx_setup2d(currentWindowWidth, currentWindowHeight);

			//control de tamaño
			flameSize = isIncreasing ? flameSize += 0.05f * elapsed_seconds : flameSize -= 0.05f * elapsed_seconds;

			if (flameSize >= maxFlameSize)
			{
				isIncreasing = false;
			}
			else if (flameSize <= minFlameSize)
			{
				isIncreasing = true;
			}

			//control de rotación
			if (isRotPositive == true) { //si rota a la derecha
				rotAngle = 10.f * elapsed_seconds;
				angle += 10.f;
				if (angle >= maxAngle) //lega a 1.2 y cambiamos a rotar a la izquierda
				{
					isRotPositive = false;
				}
			}
			else
			{
				rotAngle = -10.f * elapsed_seconds;
				angle -= 10.f;
				if (angle <= minAngle) //lega a 0.8 y cambiamos a rotar a la izquierda
				{
					isRotPositive = true;
				}
			}

			//Fondo
			lgfx_clearcolorbuffer(1.f, 1.f, 1.f);


			glfwGetWindowSize(window, pCurrentWindowWidth, pCurrentWindowHeight);

			//insertar texturas con el mezclado correspondiente

			//pared
			lgfx_setblend(BLEND_ALPHA);
			loadBackground(wallTexture, wallWidth, wallHeight, currentWindowWidth, currentWindowHeight);
			
			//fuego
			lgfx_setblend(BLEND_ADD);
			ltex_drawrotsized(fireTexture, mousePosX, mousePosY, rotAngle, 0.5, 0.5, fireWidth*flameSize, fireHeight*flameSize, 0, 0, 1, 1);

			//alambre
			lgfx_setblend(BLEND_ALPHA);
			loadBackground(grilleTexture, grilleWidth, grilleHeight, currentWindowWidth, currentWindowHeight);
			
			//haz de luz
			lgfx_setblend(BLEND_MUL);
			ltex_drawrotsized(lightTexture, mousePosX, mousePosY, 0, 0.5, 0.5,lightWidth, lightHeight, 0, 0, 1, 1);

			//rectangulos negros para cubrir fuera de los bordes de la textura haz de luz
			lgfx_setcolor(0, 0, 0, 0);
			//mousePos es la esquina izq superior del cuadrado
			lgfx_drawrect(mousePosX + lightWidth/2, mousePosY - lightHeight/2 -10000, 10000, 20000); //der
			lgfx_drawrect(mousePosX - lightWidth/2, mousePosY - lightHeight/2 -10000, 20000, 10000); //arr
			lgfx_drawrect(mousePosX - lightWidth/2 -10000, mousePosY - lightHeight/2 - 10000, 10000, 20000); //izq
			lgfx_drawrect(mousePosX - lightWidth/2, mousePosY + lightHeight/2, 20000, 10000); //abj
			
		
			glfwGetCursorPos(window, pMouseX, pMouseY);

			std::string title =
				+ "-- Tam de llama: "
				+ stringFromNumber(flameSize)
				+"-- Angulo: "
				+ stringFromNumber(angle);

			glfwSetWindowTitle(window, title.c_str());
			glfwSwapBuffers(window);

			//check and call events
			glfwPollEvents();

		}
		ltex_free(wallTexture);
		ltex_free(fireTexture);
		ltex_free(grilleTexture);
		ltex_free(lightTexture);
		stbi_image_free(bytesPerPixel);

	}

	glfwTerminate();
	return 0;
}
