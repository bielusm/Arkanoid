#include "Paddle.h"
#define XVEL 300.0f

Paddle::Paddle(float left, float top, float right, float bottom, float padding_in)
{
	rect = Rect(left, right, top, bottom);

	padding = padding_in;
	paddedRect = rect - padding;

	xVel = XVEL;
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
		rect.left -= xVel * dt;
		rect.right -= xVel * dt;
	}
	else if (kbd->isPressed(VK_RIGHT))
	{
		rect.right += xVel * dt;
		rect.left += xVel * dt;
	}
	paddedRect = rect - padding;
}

void Paddle::draw(Graphics *gfx)
{
	gfx->DrawRect(paddedRect, 255.0f, 0.0f, 0.0f, 1.0f, true);
	gfx->DrawRect(rect, 0.0f, 0.0f, 0.0f, 1.0f, false);
}