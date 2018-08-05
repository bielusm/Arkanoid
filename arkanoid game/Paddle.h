#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle() = default;
	Paddle(float left_in, float top_in, float right_in, float bottom_in);
	~Paddle();

	void update(Keyboard *kbd, float dt);
	void draw(Graphics *gfx);
private:
	float left;
	float top;
	float right;
	float bottom;
	float xVel;
};

