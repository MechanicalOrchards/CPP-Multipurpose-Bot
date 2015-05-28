#define winver 0x0500
#include <windows.h>
#include "stdafx.h"

enum mType { leftButton, rightButton };

void mClick(mType button, int howLong, int manyTimes);
void pressKey(WORD keyWord, int howLong, int manyTimes);


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

void mClick(mType button, int howLong, int manyTimes) // Takes a enum determining which button to use, an int that determines how long to hold down the button, and an int to determine how many clicks.
{

	INPUT click;
	click.type = INPUT_MOUSE;
	click.mi.time = 0;

	switch(button)
	{
		case leftButton:
			for (int i = 0; manyTimes > i; i++)
			{
				click.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
				SendInput(1, &click, sizeof(INPUT));
				Sleep(howLong);
				click.mi.dwFlags = MOUSEEVENTF_LEFTUP;
				SendInput(1, &click, sizeof(INPUT));
			}

		break;

		case rightButton:
			for (int i = 0; manyTimes > i; i++)
			{
				click.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
				SendInput(1, &click, sizeof(INPUT));
				Sleep(howLong);
				click.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
				SendInput(1, &click, sizeof(INPUT));
			}
		break;
	}


}



void pressKey(WORD keyWord, int howLong, int manyTimes) // WORD keyWord is a vk. Other args are same as the ot
{

	INPUT key;
	key.type = INPUT_KEYBOARD;
	key.ki.time = 0;
	key.ki.wVk = keyWord;

	for (int i = 0; manyTimes > i; i++)
	{
	
		key.ki.dwFlags = 0;
		SendInput(1, &key, sizeof(INPUT));
		key.ki.dwFlags = KEYEVENTF_KEYUP;
		Sleep(howLong);
		SendInput(1, &key, sizeof(INPUT));

	}

}
