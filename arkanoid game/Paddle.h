#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Rect.h"

class Paddle
{
public:
	Paddle() = default;
	Paddle(float left_in, float top_in, float right_in, float bottom_in, float padding);
	~Paddle();

	Rect GetRect();

	void update(Keyboard *kbd, float dt);
	void draw(Graphics *gfx);
private:
	Rect rect;
	Rect paddedRect;
	float xVel;
	float padding;
};

