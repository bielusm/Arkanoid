#include "Brick.h"

Brick::Brick(Rect rect_in)
{
	rect = rect_in;
	destroyed = false;
}

Brick::Brick(float left, float top, float right, float bottom)
{
	rect.left = left;
	rect.top = top;
	rect.right = right;
	rect.bottom = bottom;
	destroyed = false;
}

void Brick::Draw(Graphics *gfx)
{
	if (!destroyed)
	{
		gfx->DrawRect(rect, 255.0f, 0.0f, 0.0f, 1.0f);
	}
}

void Brick::Destroy()
{
	destroyed = true;
}

bool Brick::IsDestroyed()
{
	return destroyed;
}

Rect Brick::GetRect()
{
	return rect;
}
