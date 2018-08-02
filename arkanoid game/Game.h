#pragma once
#include "ball.h"
#include "Mouse.h"
class Game
{
public:
	Game() = default;
	Game(HWND hwnd, Mouse *mouse);
	~Game();
	void go(float dt);

private: 
	void update(float dt);
	void draw();

	Ball ball;
	Graphics *gfx;
	Mouse *mouse;
};

