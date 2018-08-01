#include "ball.h"
#include "Graphics.h"




Ball::Ball(float x_in, float y_in, float radius_in, float vel_in)
{
	x = x_in;
	y = y_in;
	radius = radius_in;
	xVel = vel_in;
	yVel = vel_in;
}

Ball::~Ball()
{
}

void Ball::Update(float dt)
{
	x += dt * xVel;
	if (x > SCREEN_WIDTH || x < 0)
	{
		xVel = -xVel;
	}

	y += dt * yVel;
	if (y > SCREEN_WIDTH || y < 0)
	{
		yVel = -yVel;
	}
}

void Ball::Draw(Graphics *gfx)
{
	gfx->DrawCircle(x, y, radius, 255.0f, 0.0f, 0.0f, 1.0f);
}
