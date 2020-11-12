#include "../../common/stdafx.h"
#include "../../common/core.h"
#include "global.h"
#include "../../common/sys.h"

#define MAX_BALL_SPEED = 8.f;	// Max vel. of ball. (pixels/?).

tBalls balls; //Arrays of balls.
GLuint texsmallball; 
GLuint texbkg;


void InitGlobalData()
{
	// Load textures
	GLuint texbkg = CORE_LoadPNG("data/circle-bkg-128.png", true);
	GLuint texsmallball = CORE_LoadPNG("data/tyrian_ball.png", false);

	// Init game state.
	for (int i = 0; i < NUM_BALLS; i++) {
		balls[i].pos = vec2(CORE_FRand(0.0, SCR_WIDTH), CORE_FRand(0.0, SCR_HEIGHT));
		balls[i].vel = vec2(CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED), CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED));
		balls[i].radius = 16.f;
		balls[i].gfx = texsmallball;
	}
}

void ShutDownGlobalData()