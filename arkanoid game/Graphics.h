#pragma once
#include <windows.h>
#include <assert.h>
#include <D2D1.h>
#include "Rect.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


class Graphics
{
public:
	Graphics();
	~Graphics();

	bool Init(HWND hWnd);
	void BeginDraw() { renderTarget->BeginDraw(); }
	HRESULT EndDraw() { return renderTarget->EndDraw(); }

	void ClearScreen(float r, float g, float b);
	void DrawCircle(float x, float y, float radius, float r, float g, float b, float a);

	void DrawRect(Rect rect, float r, float g, float b, float a);
	void DrawRect(float left, float top, float right, float bottom, float r, float g, float b, float a);
private:
	// global declarations
	ID2D1Factory *factory;
	ID2D1HwndRenderTarget *renderTarget;
};

