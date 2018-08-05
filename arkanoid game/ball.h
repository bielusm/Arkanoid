#pragma once
#include "Graphics.h"
#include "Mouse.h"
#include "Rect.h"
#include <cmath>
#include "Point.h"


class Ball
{
public:
	Ball() = default;
	Ball(float x, float y, float size, float vel);
	~Ball();

	void AllowCollision();
	void Update(float dt);
	bool Collided(Rect rect, float dt);
	void UpdateWithMouse(Mouse *mouse);
	void Draw(Graphics *gfx);
private:
	float Distance(Point a, Point b);
	bool closer(float x, float a, float b);
	ClosestPoint FindClosestPoint(Point p, Rect rect);
	bool canCollide;
	float x;
	float y;
	float radius;
	float xVel;
	float yVel;
	bool visible = true;
	bool blue;
};

