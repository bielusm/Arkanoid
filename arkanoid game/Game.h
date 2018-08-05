#pragma once
#include "ball.h"
#include "Mouse.h"
#include "Paddle.h"
#include "Brick.h"

#define NUM_BRICKS 80

class Game
{
public:
	Game() = default;
	Game(HWND hwnd, Mouse *mouse, Keyboard *keyboard);
	~Game();
	void go(float dt);

private: 
	void update(float dt);
	void draw();

	Paddle paddle;
	Ball ball;
	Graphics *gfx;
	Mouse *mouse;
	Keyboard *keyboard;
	Brick bricks[NUM_BRICKS];
};

