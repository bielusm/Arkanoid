#include "Game.h"



Game::Game(HWND hWnd, Mouse *mouse_in)
{
	gfx = new Graphics();
	if (!gfx->Init(hWnd))
	{
		//error
	}
	mouse = mouse_in;
	ball = Ball(100, 0, 5, 200);
	paddle = Paddle(0, 0, 200, 200);
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
	//ball.Update(dt);
	ball.UpdateWithMouse(mouse);
	paddle.update();
}

void Game::draw()
{
	gfx->BeginDraw();
	gfx->ClearScreen(0, 0, 0);
	ball.Draw(gfx);
	paddle.draw(gfx);
	HRESULT hres = gfx->EndDraw();

}