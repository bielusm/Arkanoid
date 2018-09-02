#include "Rect.h"

Rect::Rect(float left_in, float right_in, float top_in, float bottom_in)
{
	left = left_in;
	right = right_in;
	bottom = bottom_in;
	top = top_in;
}

Rect Rect::operator-(const float num)
{
	Rect temp;
	temp.bottom = bottom - num;
	temp.top = top + num;
	temp.right = right - num;
	temp.left = left + num;
	return temp;
}