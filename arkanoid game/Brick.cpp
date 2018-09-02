#include "Brick.h"

Brick::Brick(Rect rect_in, float r_in, float g_in, float b_in, float padding)
{
	rect = rect_in;
	paddedRect = rect - padding;

	destroyed = false;
	r = r_in;
	g = g_in;
	b = b_in;
	
}

Brick::Brick(float left, float top, float right, float bottom, float r_in, float g_in, float b_in, float padding)
{
	rect = Rect(left, right, top, bottom);
	paddedRect = rect - padding;

	r = r_in;
	g = g_in;
	b = b_in;
	destroyed = false;
}

void Brick::Draw(Graphics *gfx)
{
	if (!destroyed)
	{
		gfx->DrawRect(paddedRect, r, g, b, 1.0f, true);
		gfx->DrawRect(rect, 0.0f, 0.0f, 0.0f, 1.0f, false);
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
