#pragma once
#include "Rect.h"
#include "Graphics.h"
#include "ball.h"
class Brick
{
public:
	Brick() = default;
	Brick(float left, float top, float right, float bottom, float r_in, float g_in, float b_in, float padding);
	Brick(Rect rect, float r_in, float g_in, float b_in, float padding);
	Rect GetRect();
	void Draw(Graphics *gfx);
	bool IsDestroyed();
	void Destroy();
private:
	Rect rect;
	Rect paddedRect;
	bool destroyed;
	float r;
	float g;
	float b;
};

