#pragma once
#include "Graphics.h"
#include "Mouse.h"
#include "Rect.h"
class Ball
{
public:
	Ball() = default;
	Ball(float x, float y, float size, float vel);
	~Ball();
	void AllowCollision();
	void Update(float dt);
	bool Collided(Rect rect);
	void UpdateWithMouse(Mouse *mouse);
	void Draw(Graphics *gfx);

private:
	bool canCollide;
	float x;
	float y;
	float radius;
	float xVel;
	float yVel;
	bool visible = true;
	bool blue;
};

