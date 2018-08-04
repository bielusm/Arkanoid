#include "win32.h"

#pragma comment(lib, "d2d1")

int CALLBACK WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	Window(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}