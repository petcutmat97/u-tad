#include "../../common/vector2d.h"


struct Ball	// Info Ball
{
	vec2   pos;	// Position.
	vec2   vel;	// Velocity.
	GLuint gfx;	// OpenGL for id. for visualization purposes. 
	float  radius;	// Radius.

	Ball() :
		pos(0.0f),
		vel(0.0f),
		gfx(0),
		radius(0.0f)
	{}
};

const unsigned int NUM_BALLS = 10;	// Max. num balls.

typedef Ball balls[NUM_BALLS];	// Array of balls.