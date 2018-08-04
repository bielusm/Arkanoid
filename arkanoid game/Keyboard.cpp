#include "Keyboard.h"



Keyboard::Keyboard()
{
	for (int i = 0; i <= VK_OEM_CLEAR; i++)
		pressed[i] = false;
}


Keyboard::~Keyboard()
{
}

bool Keyboard::isPressed(int virtualKey)
{
	return pressed[virtualKey];
}

void Keyboard::pressKey(int virtualKey)
{
	pressed[virtualKey] = true;
}

void Keyboard::releaseKey(int virtualKey)
{
	pressed[virtualKey] = false;
}
