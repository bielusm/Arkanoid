#pragma once
#include <Windows.h>

class Keyboard
{
public:
	Keyboard();
	~Keyboard();

	void pressKey(int virtualKey);
	void releaseKey(int virtualKey);

	bool isPressed(int virtualKey);
private:
	bool pressed[VK_OEM_CLEAR+1];
};

