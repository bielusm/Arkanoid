#pragma once
#include "ball.h"
#include "Mouse.h"
#include "Paddle.h"
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

	Paddle paddle;
	Ball ball;
	Graphics *gfx;
	Mouse *mouse;
};

