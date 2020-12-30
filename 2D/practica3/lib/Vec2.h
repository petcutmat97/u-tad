#pragma once

#include <iostream>

#include <cmath>

class Vec2
{
private:

	float x;
	float y;

public:

	Vec2(float x, float y);
	Vec2();

	float getX() {
		return this->x;
	};
	float getY() {
		return this->y;
	};

	Vec2 getVec2() {
		return Vec2(this->x, this->y);
	};

	//Suma, resta, producto y división
	Vec2 sumVec2(const Vec2& other);
	Vec2 diffVec2(const Vec2& other);
	Vec2 prodVec2(const float num);
	Vec2 divVec2(const float num);

	//Valor absoluto
	Vec2 absVec2();

	//Longitud
	float lenVec2();

	//Normal
	float normVec2();

	//Producto escalar
	float dotProdVec2(const Vec2& other);

	//Métodos extra
	float angleVec2(const Vec2& other);
	float distanceVec2(const Vec2& other);

};

