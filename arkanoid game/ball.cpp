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

float Ball::Distance(Point a, Point b)
{
	return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

bool Ball::closer(float x, float a, float b)
{
	if (std::abs(a - x) - std::abs(b - x) > 0)
		return false;
	else
		return true;
}

//only checks if x is closer to point need to check (x,y)
//eventually use a quadtree



ClosestPoint Ball::FindClosestPoint(Point p, Rect rect)
{
	float centerX = (rect.left + rect.right) / 2;
	float centerY = (rect.top + rect.bottom) / 2;
	Point topPoint(x, rect.top);
	Point bottomPoint(x, rect.bottom);
	Point leftPoint(rect.left, y);
	Point rightPoint(rect.right, y);

	if (Distance(p, topPoint) < Distance(p, bottomPoint))
	{
		if (Distance(p, topPoint) < Distance(p, leftPoint))
		{
			if (Distance(p, topPoint) < Distance(p, rightPoint))
				return top;
			else
				return right;
		}
		else if(Distance(p, leftPoint) < Distance(p, rightPoint))
		{
			 return left;
		}
		else
		{
			return right;

		}
	}
	else
	{
		if (Distance(p, bottomPoint) < Distance(p, leftPoint))
		{
			if (Distance(p, bottomPoint) < Distance(p, rightPoint))
				return bottom;
			else
				return right;
		}
		else if(Distance(p, leftPoint) < Distance(p, rightPoint))
		{
			 return left;
		}
		else
		{
			return right;

		}

	}


}

bool Ball::Collided(Rect rect, float dt)
{
	ClosestPoint cp;

	if (canCollide)
	{
		if (y + radius <= rect.bottom && y - radius >= rect.top && x + radius >= rect.left && x - radius <= rect.right)
		{
			cp = FindClosestPoint(Point(x,y), rect);
			switch (cp)
			{
			case left:
			case right:
				xVel = -xVel;
				canCollide = false;
				return true;
				break;
			case top:
			case bottom:
				yVel = -yVel;
				canCollide = false;
				return true;
				break;
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

