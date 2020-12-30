
#define STB_IMAGE_IMPLEMENTATION
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Font.h"
#include "stb_truetype.h"
#include <stb_image.h>

long ttf_size;
unsigned char* fontBuffer;
unsigned char* pPixels_alphaBuffer;
unsigned char* pPixels_colorBuffer;

int alphaBuffer;
int error;
int colorBuffer;

Font::Font() 
{
};

Font::~Font() 
{
};

static Font* Font::load(const char* filename, float height) {
	
	Font:height = height;
	Font* newFont = new Font();
	FILE* fontFile = fopen(filename, "rb");
	fseek(fontFile, 0, SEEK_END);
	ttf_size = ftell(fontFile, 0, SEEK_END);
	fontBuffer = (stbi_uc*)malloc(ttf_size);

	fread(fontBuffer, ttf_size, 1, fontFile);
	fclose(fontFile);

	unsigned char pBufferAlpha[512*512];

	stbtt_bakedchar chardata[256];

	error = stbtt_BakeFontBitmap(fontBuffer, 
		//tipo ttf
		0,
		height, 
		//posicion en la que lo guardamos
		pBufferAlpha, 
		//altura y anchura de la textura
		512, 512,
		//tabla ascii 0-255
		0, 255, newFont->chardata);

	unsigned char pBufferColor[512 * 512 * 4];
	int counter = 0;
	for (size_t i = 0; i < 512*512*4; i++)
	{
		pBufferColor[i] = 255;
		if (i % 4 == 3) {
			pBufferColor[i] = pBufferAlpha[i];
			counter++;
		}
		else {
			pBufferColor[i] = 255;
		}
	}

	newFont->tex = ltex_alloc(512, 512, 0);
	if (newFont->tex != nullptr) {
		ltex_setpixels(newFont->tex, pBufferColor);
	}

	return newFont;
}

float Font:getHeight() const
{
	return Font:height;
}

float Font:getTextSize(const char* text) const
{
	return Vec2();
}

void Font:draw(const char* text, const Vec2& pos) const 
{
	stbtt_GetBakedQuad()
}
}