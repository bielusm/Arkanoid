#include "Paddle.h"

Paddle::Paddle(float left_in, float top_in, float right_in, float bottom_in)
{
	left = left_in;
	top = top_in;
	right = right_in;
	bottom = bottom_in;
}

Paddle::~Paddle()
{
}

void Paddle::update()
{

}

void Paddle::draw(Graphics *gfx)
{
	gfx->DrawRect(left, top, right, bottom, 255.0f, 0.0f, 0.0f, 1.0f);
}