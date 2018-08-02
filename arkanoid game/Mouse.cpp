#include "Mouse.h"



Mouse::Mouse()
{
	point.x = 0;
	point.y = 0;
}


Mouse::~Mouse()
{
}

void Mouse::SetPos(Point p)
{
	point.x = p.x;
	point.y = p.y;
}

Point Mouse::GetPos()
{
	return point;
}
