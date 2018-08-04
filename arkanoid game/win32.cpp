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

HWND Window::createWindow()
{
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(WNDCLASSEX));

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hInstance;
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
		false); // no menu

	HWND hWnd = CreateWindow(
		wcex.lpszClassName,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		(wr.right - wr.left),
		(wr.bottom - wr.top),
		NULL,
		NULL,
		m_hInstance,
		NULL);
	if (!hWnd)
	{
		PrintErrorMsg();
	}

	return hWnd;
}

	Window::Window(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
	{
	m_hInstance = hInstance;
	m_windowClassName = "szWindowClass";
	
	HWND hWnd = createWindow();
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	mouse = new Mouse();
	game = new Game(hWnd, mouse);
	messageLoop(hWnd);
}

int Window::messageLoop(HWND hWnd)
{
	float lag = 0.0f;
	float moveAmount;
	auto prevTime = hrClock::now();
	auto currTime = hrClock::now();

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
		currTime = hrClock::now();
		fsec fs = currTime - prevTime;
		prevTime = currTime;
		lag = fs.count();
		while (lag > 0)
		{
			moveAmount = min(timestep, lag);
			lag -= moveAmount;
			game->go(moveAmount);
		}
	}
	return (int)msg.wParam;
}

Window::~Window()
{
	delete game;
	delete mouse;
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
			mouse->pressLeft();
		} break;
		case WM_LBUTTONUP:
		{
			mouse->releaseLeft();
		} break;
		case WM_RBUTTONDOWN:
		{
			mouse->pressRight();
		} break;
		case WM_RBUTTONUP:
		{
			mouse->releaseRight();
		} break;
		case WM_KEYDOWN:
		{
			int x;
			int virtualKey = wParam;
			if (wParam == VK_LEFT)
				x = 1;
			else if (wParam == VK_RIGHT)
				x = 2;

		}
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
