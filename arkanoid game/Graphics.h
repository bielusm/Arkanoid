#pragma once
#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <assert.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


class Graphics
{
public:
	Graphics();
	void InitD3D(HWND hWnd);     // sets up and initializes Direct3D
	void CleanD3D(void);         // closes Direct3D and releases memory
	void RenderFrame(void);
private:
	// global declarations
	IDXGISwapChain * swapchain;             // the pointer to the swap chain interface
	ID3D11Device *dev;                     // the pointer to our Direct3D device interface
	ID3D11DeviceContext *devcon;           // the pointer to our Direct3D device context
	ID3D11RenderTargetView *backbuffer;   


	bool initialized = false;
};

