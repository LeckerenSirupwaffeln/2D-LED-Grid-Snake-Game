#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#include "GlobalDefines.h"
#include "SnakeGame.h"
#include "LEDGrid.h"
#include "Buttons.h"
#include "Buzzer.h"
#include "Menu.h"
#include "Test.h"

int General_CFG(void);
DWORD WINAPI ThreadUserInput(LPVOID lpParam);
DWORD WINAPI ThreadSoundControl(LPVOID lpParam);

int CurrentState, CurrentSound, CurrentDirection, IsSoundActive =
		0;

int main(void) {
	General_CFG();
	while (1) {
		switch (CurrentState) {
		case StartMenu:
			Game_StartMenu(&CurrentSound,&CurrentState, &LEDGrid);
			break;
		case GameConfigure:
			Game_CFG(&CurrentState);
			break;
		case PauseMenu:
			Game_PauseMenu(&CurrentSound,&CurrentState);
			break;
		case SnakeGame:
			Game_Snake(&CurrentState, &CurrentDirection, &CurrentSound,
					&LEDGrid);
			break;
		case Test:
			TestOutput(&CurrentState, &CurrentSound, &LEDGrid);
			break;
		}

	}

	return 0;
}

int General_CFG(void) {
	Sleep(400);
	setvbuf(stdout, NULL, _IONBF, 0); //eclipse specific code to allow the game to run slowly
	CurrentDirection = Right;
	HANDLE thread0 = CreateThread(NULL, 0, ThreadSoundControl, NULL, 0, NULL);
	SetThreadPriority(thread0, THREAD_PRIORITY_BELOW_NORMAL);
	HANDLE thread1 = CreateThread(NULL, 0, ThreadUserInput, NULL, 0, NULL);
	SetThreadPriority(thread1, THREAD_PRIORITY_ABOVE_NORMAL);
	CurrentState = StartMenu;
	return E_CFG_READY;
}

DWORD WINAPI ThreadUserInput(LPVOID lpParam) {
	Check_User_Input(&CurrentDirection, &CurrentSound, &CurrentState);
	return 0;
}

DWORD WINAPI ThreadSoundControl(LPVOID lpParam) {
	SoundControl(&CurrentSound, &CurrentState);
	return 0;
}
