#include <Windows.h>
#include <stdio.h>

#include "GlobalDefines.h"
#include "Menu.h"

int Game_StartMenu(int *ptrCurrentSound, int *ptrCurrentState,
		void (*ptrfuncLEDGrid)(int *ptrarrayLEDGrid)) {
	int bufferarray[GRIDSIZE];
	FILE *topscorefile;
	topscorefile = fopen("topscore.txt", "r");
	int topscore = fgetc(topscorefile);
	for (int i = 0; i < GRIDSIZE; i++) {
		bufferarray[i] = Empty; //Fill the board with dots
	}
	int tmpnumber = 0;
	for (int y = 1; y < GRIDLENGTH - 1; y++) {
		for (int x = 1; x < GRIDLENGTH - 1; x++) {
			bufferarray[y * GRIDLENGTH + x] = Snake;
			tmpnumber++;
			if(tmpnumber >=topscore){break;}
		}
		if(tmpnumber >=topscore){break;}
	}

	ptrfuncLEDGrid(bufferarray);
	//printf("\nTOPSCORE:%d",topscore); debug func
	while (*ptrCurrentState == StartMenu) {
		*ptrCurrentSound = SoundStart;
		Sleep(500); //try to play sound every 500ms
	}
	fclose(topscorefile);
	return E_CONT;
}

int Game_PauseMenu(int *ptrCurrentSound, int *ptrCurrentState) {
	while (*ptrCurrentState == PauseMenu) {
		*ptrCurrentSound = SoundPause;
		Sleep(500); //try to play sound every 500ms
	}
	return E_CONT;
}
