#include "GlobalDefines.h"
#include "Test.h"

#include <Windows.h>

int TestOutput(int *ptrCurrentState, int *ptrCurrentSound,
		void (*ptrfuncLEDGrid)(int *ptrarrayLEDGrid)) {
	int bufferarray[GRIDSIZE];
	for (int i = 0; i < GRIDSIZE; i++) {
		if (!(i % 2)) {
			bufferarray[i] = Snake;
		} else {
			bufferarray[i] = Fruit;
		}
	}
	ptrfuncLEDGrid(bufferarray);
	*ptrCurrentSound = SoundStart;
	Sleep(2000); //wait 2 secs in test mode
	*ptrCurrentState = StartMenu; //switch back to StartMenu
	return E_CONT;
}
