#include "win32.h"



const char * m_windowClassName;
HINSTANCE m_hInstance;


void PrintErrorMsg()
{
	LPTSTR errorText = NULL;

	FormatMessage(
		// use system message tables to retrieve error text
		FORMAT_MESSAGE_FROM_SYSTEM
		// allocate buffer on local heap for error text
		| FORMAT_MESSAGE_ALLOCATE_BUFFER
		// Important! will fail otherwise, since we're not 
		// (and CANNOT) pass insertion parameters
		| FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,    // unused with FORMAT_MESSAGE_FROM_SYSTEM
		GetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&errorText,  // output 
		0, // minimum size for output buffer
		NULL);   // arguments - see note 

	if (NULL != errorText)
	{
		MessageBox(NULL,
			_T(errorText),
			_T("ERROR"),
			NULL);

		// release memory allocated by FormatMessage()
		LocalFree(errorText);
		errorText = NULL;
	}
}




int CALLBACK WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	m_hInstance = hInstance;
	m_windowClassName = "szWindowClass";
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(WNDCLASSEX));

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance; 
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszClassName = m_windowClassName;

	if (!RegisterClassEx(&wcex))
	{
		PrintErrorMsg();
		return 1;
	}

	static TCHAR szTitle[] = _T("Windows App");

	RECT wr = { 0,0,500,100 };
	int width = SCREEN_WIDTH;
	int height = SCREEN_HEIGHT;
	SetRect(&wr, 0, 0, width, height);
	AdjustWindowRect(&wr,
		WS_OVERLAPPEDWINDOW,
		false ); // no menu

	HWND hWnd = CreateWindow(
		wcex.lpszClassName,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		(wr.right-wr.left),
		(wr.bottom-wr.top),
		NULL,
		NULL,
		hInstance,
		NULL);
	if (!hWnd)
	{
		PrintErrorMsg();
		return 1;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	renderer.InitD3D(hWnd);

	//main message loop
	bool gotMsg;
	MSG msg;
	msg.message = WM_NULL;
	PeekMessage(&msg, hWnd, 0, 0, PM_NOREMOVE);

	while (TRUE)
	{
		gotMsg = PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
		if (gotMsg)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
				break;

		}
			int a = 2;
			//game logic
			//hangs because only rendering in message window
			renderer.RenderFrame();
	}

	renderer.CleanD3D();
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;

		} break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

