#include "win32.h"

void Window::PrintErrorMsg()
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

	Window::Window(HINSTANCE hInstance,
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
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//main message loop

	mouse = new Mouse();
	game = new Game(hWnd, mouse);


	bool gotMsg;
	MSG msg;
	msg.message = WM_NULL;
	PeekMessage(&msg, hWnd, 0, 0, PM_NOREMOVE);

	float lag = 0.0f;
	auto t0 = hrClock::now();
	auto t1 = hrClock::now();
	float moveAmount;
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
		t1 = hrClock::now();
		fsec fs = t1 - t0;
		t0 = t1;
		lag = fs.count();
		while (lag > 0)
		{
			moveAmount = min(timestep, lag);
			lag -= moveAmount;
			game->go(moveAmount);
		}
	}
	delete game;
	delete mouse;
//	return (int)msg.wParam; might need to move this out of constructor for return
}

Window::~Window()
{

}

LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		} break;
		case WM_MOUSEMOVE:
		{
			int xPos = GET_X_LPARAM(lParam);
			int yPos = GET_Y_LPARAM(lParam);
			Point p;
			p.x = xPos;
			p.y = yPos;
			mouse->SetPos(p);
		} break;
		case WM_LBUTTONDOWN:
		{
			mouse->leftPressed();
		} break;
		case WM_LBUTTONUP:
		{
			mouse->releaseLeft();
		} break;
		case WM_RBUTTONDOWN:
		{
			mouse->rightPressed();
		} break;
		case WM_RBUTTONUP:
		{
			mouse->releaseRight();
		} break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
