#include "Game.h"



Game::Game(HWND hWnd)
{
	gfx = new Graphics();
	if (!gfx->Init(hWnd))
	{
		//error
	}
	ball = Ball(100, 0, 5, 200);
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
	ball.Update(dt);
}

void Game::draw()
{
	gfx->BeginDraw();
	gfx->ClearScreen(0, 0, 0);
	ball.Draw(gfx);
	gfx->EndDraw();

}