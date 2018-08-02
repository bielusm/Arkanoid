#pragma once
#include "Graphics.h"
#include "Mouse.h"
class Ball
{
public:
	Ball() = default;
	Ball(float x, float y, float size, float vel);
	~Ball();
	void Update(float dt);
	void UpdateWithMouse(Mouse *mouse);
	void Draw(Graphics *gfx);

private:
	float x;
	float y;
	float radius;
	float xVel;
	float yVel;
	bool visible = true;
};

