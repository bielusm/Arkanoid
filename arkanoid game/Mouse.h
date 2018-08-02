#pragma once
#include "Point.h"

class Mouse
{
public:
	Mouse();
	~Mouse();
	void SetPos(Point p);
	Point GetPos();
private:
	Point point;
};

