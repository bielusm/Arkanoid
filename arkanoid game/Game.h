#pragma once
#include "ball.h"
class Game
{
public:
	Game() = default;
	Game(HWND hwnd);
	~Game();
	void go(float dt);

private: 
	void update(float dt);
	void draw();

	Ball ball;
	Graphics *gfx;
};

