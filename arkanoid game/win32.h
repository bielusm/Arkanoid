#pragma once
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include "Graphics.h"
#include "Game.h"
#include "Mouse.h"
#include <chrono>
#include <Windowsx.h>
#include "Mouse.h"
#include "Keyboard.h"

typedef std::chrono::high_resolution_clock hrClock;
typedef std::chrono::milliseconds ms;
typedef std::chrono::duration<float> fsec;
using namespace std::chrono_literals;
constexpr float timestep = 0.16f;

static Mouse *mouse;
static Keyboard *keyboard;

class Window
{
public:
	Window(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
	~Window();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void PrintErrorMsg();
	int messageLoop(HWND hwnd);
	HWND createWindow();
	Game *game;

private:
	const char * m_windowClassName;
	HINSTANCE m_hInstance;
};
