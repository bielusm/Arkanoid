#include "Game.h"



Game::Game(HWND hWnd, Mouse *mouse_in, Keyboard *keyboard_in)
{
	gfx = new Graphics();
	if (!gfx->Init(hWnd))
	{
		//error
	}
	mouse = mouse_in;
	ball = Ball(300, 300, 5, 200);
	paddle = Paddle(400, 475, 500, 500);
	keyboard = keyboard_in;
	float y = 25;
	float x = 100;
	for (int i = 0; i < NUM_BRICKS; i++)
	{
		x += 55;
		if (i % 10 == 0)
		{
			y += 30;
			x = 100;
		}
			bricks[i] = Brick(x, y, x + 50, y+25);
	}
}


Game::~Game()
{
	delete gfx;
}

void Game::go(float dt)
{
	update(dt);
	draw();
}

void Game::update(float dt)
{
	ball.Collided(paddle.GetRect());
	for (int i = 0; i < NUM_BRICKS; i++)
	{
		if (!bricks[i].IsDestroyed() && ball.Collided(bricks[i].GetRect()))
		{
			bricks[i].Destroy();
			ball.AllowCollision();
		}
	}
	ball.Update(dt);
	paddle.update(keyboard, dt);
}

void Game::draw()
{
	gfx->BeginDraw();
	gfx->ClearScreen(255.0f, 255.0f, 255.0f);
	ball.Draw(gfx);
	paddle.draw(gfx);
	
	for (int i = 0; i < NUM_BRICKS; i++)
	{
		bricks[i].Draw(gfx);
	}
	HRESULT hres = gfx->EndDraw();
}