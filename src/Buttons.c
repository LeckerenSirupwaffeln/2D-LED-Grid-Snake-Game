#include <windows.h>
#include <stdio.h>

#include "GlobalDefines.h"
#include "Buttons.h"

int weirdcompilerstuff = 1;
int weirdcompilerstuff2 = 1;

void Check_User_Input(int *ptrCurrentDirection, int *ptrCurrentSound,
		int *ptrCurrentState) {
	while (1) {
		if (GetAsyncKeyState(E_RIGHT_KEY) < 0) {
			if (*ptrCurrentDirection != Left) {
				*ptrCurrentDirection = Right;
			}
		}

		if (GetAsyncKeyState(E_LEFT_KEY) < 0) {
			if (*ptrCurrentDirection != Right) {
				*ptrCurrentDirection = Left;
			}
		}

		if (GetAsyncKeyState(E_UP_KEY) < 0) {
			if (*ptrCurrentDirection != Down) {
				*ptrCurrentDirection = Up;
			}
		}

		if (GetAsyncKeyState(E_DOWN_KEY) < 0) {
			if (*ptrCurrentDirection != Up) {
				*ptrCurrentDirection = Down;
			}
		}
		if (GetAsyncKeyState(E_SR_KEY) < 0) {
			switch (*ptrCurrentState) {
			case StartMenu:
				*ptrCurrentState = GameConfigure;
				break;
			case SnakeGame:
				*ptrCurrentState = GameConfigure;
				break;
			case PauseMenu:
				*ptrCurrentState = SnakeGame;
				break;
			}
			Sleep(200);

		}

		if (GetAsyncKeyState(E_SP_KEY) < 0) {
			switch (*ptrCurrentState) {
			case StartMenu:
				exit(0);
				break;
			case SnakeGame:
				*ptrCurrentState = PauseMenu;
				break;
			case PauseMenu:
				*ptrCurrentState = StartMenu;
				break;
			}
			Sleep(200);

		}
		if (GetAsyncKeyState(E_TEST_KEY) < 0) {
			if (*ptrCurrentState == StartMenu) {
				*ptrCurrentState = Test;
			}
		}
	}
}
