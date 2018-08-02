#pragma once
#include "Point.h"

class Mouse
{
public:
	Mouse();
	~Mouse();
	void SetPos(Point p);
	Point GetPos();
	void pressLeft();
	void releaseLeft();
	void pressRight();
	void releaseRight();

	bool leftPressed();
	bool rightPressed();

private:
	Point point;
	bool leftClickPressed;
	bool rightClickPressed;
};

