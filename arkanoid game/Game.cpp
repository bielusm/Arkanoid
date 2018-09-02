#include "Game.h"
#define RED 0
#define BLUE 1
#define GREEN 2
#define NOCOLOR 3


Game::Game(HWND hWnd, Mouse *mouse_in, Keyboard *keyboard_in)
{
	gfx = new Graphics();
	if (!gfx->Init(hWnd))
	{
		//error
	}
	mouse = mouse_in;
	ball = Ball(300, 300, 5, 200);
	paddle = Paddle(400, 475, 500, 500, 2.5f);
	keyboard = keyboard_in;
	float y = 25;
	float x = 100;
	float r, g, b = 0;
	int color = RED;
	float padding = 2.5f;

	for (int i = 0; i < NUM_BRICKS; i++)
	{
		x += 50;
		if (i % 10 == 0)
		{
			y += 25;
			x = 100;
			color++;
			if (color == NOCOLOR)
				color = RED;
		}
		r = 0;
		g = 0;
		b = 0;
		if (color == RED)
			r = 255;
		else if (color == GREEN)
			g = 255;
		else
			b = 255;
		bricks[i] = Brick(x, y, x + 50, y + 25, r, g, b, padding);
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
	ball.Collided(paddle.GetRect(), dt);
	for (int i = 0; i < NUM_BRICKS; i++)
	{
		if (!bricks[i].IsDestroyed() && ball.Collided(bricks[i].GetRect(), dt))
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
	gfx->ClearScreen(1.0f, 1.0f, 1.0f);
	ball.Draw(gfx);
	paddle.draw(gfx);
	
	for (int i = 0; i < NUM_BRICKS; i++)
	{
		bricks[i].Draw(gfx);
	}
	HRESULT hres = gfx->EndDraw();
}