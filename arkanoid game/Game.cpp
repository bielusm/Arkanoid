#include "Game.h"



Game::Game(HWND hWnd, Mouse *mouse_in, Keyboard *keyboard_in)
{
	gfx = new Graphics();
	if (!gfx->Init(hWnd))
	{
		//error
	}
	mouse = mouse_in;
	ball = Ball(100, 100, 5, 200);
	paddle = Paddle(400, 475, 500, 500);
	keyboard = keyboard_in;
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
	ball.Update(dt);
	paddle.update(keyboard, dt);
}

void Game::draw()
{
	gfx->BeginDraw();
	gfx->ClearScreen(255.0f, 255.0f, 255.0f);
	ball.Draw(gfx);
	paddle.draw(gfx);
	HRESULT hres = gfx->EndDraw();

}