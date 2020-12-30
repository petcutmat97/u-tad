
#define _USE_MATH_DEFINES
#include <iostream>
#include "Vec2.h"

#include <math.h>
#include <cmath>


Vec2::Vec2(float _x, float _y)
{
	this->x = _x;
	this->y = _y;
};

//Suma
Vec2 Vec2::sumVec2(const Vec2& other)
{
	float resX = Vec2::getX() + other.x;
	float resY = Vec2::getY() + other.y;
	return Vec2(resX, resY);
};

//Resta
Vec2 Vec2::diffVec2(const Vec2& other)
{
	float resX = Vec2::getX() - other.x;
	float resY = Vec2::getY() - other.y;
	return Vec2(resX, resY);
};

// Producto - Vec2 * Scalar
Vec2 Vec2::prodVec2(const float _f)
{
	float resX = Vec2::getX() * _f;
	float resY = Vec2::getY() * _f;
	return Vec2(resX, resY);
};

// División - Vec2 / Scalar
Vec2 Vec2::divVec2(const float _f)
{
	float resX = Vec2::getX() / _f;
	float resY = Vec2::getY() / _f;
	return Vec2(resX, resY);
};

// Producto escalar
float Vec2::dotProdVec2(const Vec2& other)
{
	return (Vec2::getX() * other.x) + (Vec2::getY() * other.y);
};

// Valor absoluto
Vec2 Vec2::absVec2()
{
	float resX;
	float resY;
	resX = (Vec2::getX() < 0) ? -Vec2::getX() : Vec2::getX();
	resY = (Vec2::getY() < 0) ? -Vec2::getY() : Vec2::getY();
	return Vec2(resX, resY);
};

// Normal
float Vec2::normVec2()
{
	double resX = pow(Vec2::getX(), 2);
	double resY = pow(Vec2::getY(), 2);

	return sqrt(resX + resY);
};
