#pragma once

#define STB_TRUETYPE_IMPLEMENTATION

#include <Vec2.h>
#include "stb_truetype.h"

class Font
{
private:

	static float height;
	Vec2 textSize;
	stbtt_bakedchar chardata[256];

public:

	static Font* load(const char* filename, float height);
	float getHeight() const;
	Vec2 getTextSize(const char* text) const;
	void draw(const char* text, const Vec2& pos) const;

private:

	Font();
	~Font();
};