#pragma once
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include "Graphics.h"
#include "Game.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
void PrintErrorMsg();

Game *game;

