#pragma once

struct Rect
{
	float left;
	float top;
	float right;
	float bottom;

	Rect() = default;
	Rect(float left_in, float right_in, float top_in, float bottom_in);
	Rect operator-(const float num);
};

