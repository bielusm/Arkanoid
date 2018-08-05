#include "Paddle.h"

Paddle::Paddle(float left_in, float top_in, float right_in, float bottom_in)
{
	left = left_in;
	top = top_in;
	right = right_in;
	bottom = bottom_in;

	rect.left = left_in;
	rect.top = top_in;
	rect.right = right_in;
	rect.bottom = bottom_in;

	xVel = 300.0f;
}

Paddle::~Paddle()
{
}

Rect Paddle::GetRect()
{
	return rect;
}

void Paddle::update(Keyboard *kbd, float dt)
{
	if (kbd->isPressed(VK_LEFT))
	{
		left -= xVel * dt;
		rect.left = left;
		right -= xVel * dt;
		rect.right = right;
	}
	else if (kbd->isPressed(VK_RIGHT))
	{
		right += xVel * dt;
		rect.right = right;
		left += xVel * dt;
		rect.left = left;
	}
	
}

void Paddle::draw(Graphics *gfx)
{
	gfx->DrawRect(left, top, right, bottom, 255.0f, 0.0f, 0.0f, 1.0f);
}