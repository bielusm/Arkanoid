#pragma once
#include "Rect.h"
#include "Graphics.h"
#include "ball.h"
class Brick
{
public:
	Brick() = default;
	Brick(float left, float top, float right, float bottom);
	Brick(Rect rect);
	Rect GetRect();
	void Draw(Graphics *gfx);
	bool IsDestroyed();
	void Destroy();
private:
	Rect rect;
	bool destroyed;
};

