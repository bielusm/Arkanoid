#include "Mouse.h"

Mouse::Mouse()
{
	point.x = 0;
	point.y = 0;

	leftClickPressed = false;
	rightClickPressed = false;
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

void Mouse::pressLeft()
{
	leftClickPressed = true;
}

void Mouse::pressRight()
{
	rightClickPressed = true;
}

void Mouse::releaseLeft()
{
	leftClickPressed = false;
}

void Mouse::releaseRight()
{
	rightClickPressed = false;
}

bool Mouse::rightPressed()
{
	return rightClickPressed;
}

bool Mouse::leftPressed()
{
	return leftClickPressed;
}
