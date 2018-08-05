#pragma once

enum ClosestPoint {
	left,
	top,
	right,
	bottom
};

struct Point
{
	Point() = default;
	Point(float x_in, float y_in)
	{
		x = x_in;
		y = y_in;
	}
	float x;
	float y;
};

struct ClosestPoints
{
	ClosestPoint x;
	ClosestPoint y;
};