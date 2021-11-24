#include "Buzzer.h"
#include "GlobalDefines.h"
#include <windows.h>
#include <stdio.h>

void SoundControl(int *ptrCurrentSound, int *ptrCurrentState) {
	while (1) {
		switch (*ptrCurrentSound) {
		case None:
			break;
		case SoundSnakeMove:
			PlaySound(TEXT("snakemove.wav"), NULL, SND_ASYNC);
			*ptrCurrentSound = None; //Disable looping
			break;
		case SoundSnakeEat:
			PlaySound(TEXT("snakeeat.wav"), NULL, SND_ASYNC);
			*ptrCurrentSound = None; //Disable looping
			break;
		case SoundStart:

			PlaySound(TEXT("startmenu.wav"), NULL, SND_ASYNC);
			*ptrCurrentSound = None; //Disable looping
			while(*ptrCurrentState == StartMenu){} //wait till state changes to not loop sound
			*ptrCurrentSound = None;
			break;
		case SoundGameOver:
			PlaySound(TEXT("gameover.wav"), NULL, SND_FILENAME);
			*ptrCurrentSound = None; //Disable looping
			break;
		case SoundPause:

			PlaySound(TEXT("pause.wav"), NULL, SND_ASYNC);
			*ptrCurrentSound = None; //Disable looping
			while(*ptrCurrentState == PauseMenu){} //wait till state changes to not loop sound
			*ptrCurrentSound = None;
			break;
		}

	}
}
