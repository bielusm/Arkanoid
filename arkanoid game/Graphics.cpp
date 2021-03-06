#include "Graphics.h"

Graphics::Graphics()
{
	factory = NULL;
	renderTarget = NULL;
}

Graphics::~Graphics()
{
	if (factory) factory->Release();
	if (renderTarget) renderTarget->Release();
}

bool Graphics::Init(HWND hWnd)
{
	HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory); 
	if (res != S_OK) return false;

	RECT rect;
	GetClientRect(hWnd, &rect);

	res = factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hWnd, D2D1::SizeU(rect.right, rect.bottom)),
		&renderTarget);
	if (res != S_OK) return false;

	return true;

}

void Graphics::ClearScreen(float r, float g, float b)
{
	renderTarget->Clear(D2D1::ColorF(r, g, b));
}

void Graphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a)
{
	ID2D1SolidColorBrush *brush;
	renderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);
	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush, 3.0f) ;
	
	brush->Release();
}

void Graphics::DrawRect(Rect rect, float r, float g, float b, float a, bool filled)
{
	DrawRect(rect.left, rect.top, rect.right, rect.bottom, r, g, b, a, filled);
}
void Graphics::DrawRect(float left, float top, float right, float bottom, float r, float g, float b, float a, bool filled)
{
	ID2D1SolidColorBrush *brush;
	renderTarget->CreateSolidColorBrush(D2D1::ColorF(r,g,b, 1.0f), &brush);

	D2D1_RECT_F rect;
	rect.left = left;
	rect.bottom = bottom;
	rect.right = right;
	rect.top = top;

	if(filled)
		renderTarget->FillRectangle(&rect, brush);
	else
		renderTarget->DrawRectangle(rect, brush, 2.5f, NULL);
}
