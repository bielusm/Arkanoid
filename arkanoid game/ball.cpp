#include "ball.h"
#include "Graphics.h"




Ball::Ball(float x_in, float y_in, float radius_in, float vel_in)
{
	x = x_in;
	y = y_in;
	radius = radius_in;
	xVel = vel_in;
	yVel = vel_in;
	canCollide = true;
}

Ball::~Ball()
{
}

void Ball::Update(float dt)
{
	x += dt * xVel;
	if (x + radius> SCREEN_WIDTH || x - radius < 0)
	{
		xVel = -xVel;
		canCollide = true;
	}

	y += dt * yVel;
	if (y + radius >= SCREEN_HEIGHT || y - radius <= 0)
	{
		yVel = -yVel;
		canCollide = true;
	}
}

bool Ball::Collided(Rect rect)
{
	if (canCollide)
	{
		if (y +radius < rect.bottom && y -radius > rect.top)
		{
			if (x + radius > rect.left && x - radius < rect.right)
			{
				yVel = -yVel;
				canCollide = false;
				return true;
			}
			else if (x + radius == rect.left || x - radius == rect.right)
			{
				xVel = -xVel;
				canCollide = false;
				return true;
			}

		}
	}
	return false;
}

void Ball::UpdateWithMouse(Mouse *mouse)
{
	if (mouse->leftPressed())
		visible = true;
	else
		visible = false;

	if (mouse->rightPressed())
		blue = true;
	else
		blue = false;

	Point p = mouse->GetPos();
	x = (float)p.x;
	y = (float)p.y;
}

void Ball::Draw(Graphics *gfx)
{
	if (visible)
	{
		if(blue)
			gfx->DrawCircle(x, y, radius, 0.0f, 0.0f, 255.0f, 1.0f);
		else
			gfx->DrawCircle(x, y, radius, 255.0f, 0.0f, 0.0f, 1.0f);
	}
}
