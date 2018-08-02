#include "win32.h"

int CALLBACK WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	Window(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}