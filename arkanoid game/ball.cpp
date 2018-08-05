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
	float moveX = dt * xVel;
	float moveY = dt * yVel;
	if (x + moveX + radius >= SCREEN_WIDTH || moveX + x - radius <= 0)
	{
		xVel = -xVel;
		canCollide = true;
	}

	moveY = dt * yVel;
	if (moveY + y + radius >= SCREEN_HEIGHT || moveY + y - radius <= 0)
	{
		yVel = -yVel;
		canCollide = true;
	}
	x += xVel * dt;
	y += yVel * dt;

}

void Ball::AllowCollision()
{
	canCollide = true;
}

bool Ball::Collided(Rect rect, float dt)
{
	if (canCollide)
	{
		float center = (rect.left + rect.right) / 2;

		if (y +radius < rect.bottom && y -radius > rect.top)
		{
			if (x + radius > rect.left && x - radius < rect.right)
			{
				if (std::abs(x + (xVel * dt) - center) - std::abs(x - center) > 0)
				{
					yVel = -yVel;
					canCollide = false;
					return true;
				}
				else
				{
					xVel = -xVel;
					canCollide = false;
					return true;
				}
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
