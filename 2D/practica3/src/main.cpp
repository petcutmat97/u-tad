
#define LITE_GFX_IMPLEMENTATION

#include <litegfx.h>
#include <glfw3.h>
#include <iostream>
#include <sstream>
#include <Vec2.h>
#include <string>
#include "Font.h"

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


		Font* newFont = Font::load("/data/Orange.ttf",8);

		GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Ventana Principal", nullptr, nullptr);
		glfwMakeContextCurrent(window);
		
		while(!glfwWindowShouldClose(window))
		{

			static float previous_seconds = static_cast<float>(glfwGetTime());
			float current_seconds = static_cast<float>(glfwGetTime());

			float elapsed_seconds = current_seconds - previous_seconds;
			previous_seconds = current_seconds;

			lgfx_setup2d(currentWindowWidth, currentWindowHeight);

			
			//Fondo
			lgfx_clearcolorbuffer(1.f, 1.f, 1.f);
			

			lgfx_setblend(BLEND_ALPHA);
			ltex_draw(newFont->tex, 0, 0);
			
			
		
			glfwGetCursorPos(window, pMouseX, pMouseY);
			
			glfwSwapBuffers(window);

			glfwPollEvents();

		}
		stbi_image_free(bytesPerPixel);

	}

	glfwTerminate();
	return 0;
}
