#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#include "GlobalDefines.h"
#include "SnakeGame.h"
int GameBoard[GRIDSIZE];
StructSnakeBody SnakeBody;

int Game_Snake(int *ptrCurrentState, int *ptrCurrentDirection,
		int *ptrCurrentSound, void (*ptrfuncLEDGrid)(int *ptrarrayLEDGrid)) {
	while (*ptrCurrentState == SnakeGame) {
		ptrfuncLEDGrid(GameBoard);
		Sleep(PERIOD);
		Game_CheckCollision(ptrCurrentState, ptrCurrentDirection,
				ptrCurrentSound, ptrfuncLEDGrid);
	}

	return E_CONT;
}

int Game_CFG(int *ptrCurrentState) {
//Init game board
	for (int i = 0; i < GRIDSIZE; i++) {
		GameBoard[i] = Empty;
	}

//Init game board walls
	for (int x = 0; x < (int) sqrt(GRIDSIZE); x++) {
		GameBoard[x] = Wall;
		GameBoard[GRIDSIZE - x] = Wall;
		GameBoard[(int) sqrt(GRIDSIZE) * x] = Wall;
		GameBoard[(int) sqrt(GRIDSIZE) * x + (int) sqrt(GRIDSIZE) - 1] = Wall;
	}

//Init snake
	(SnakeBody).length = (int) SNAKESIZE;
	for (int x = 0; x < SNAKESIZE; x++) {
		GameBoard[GRIDSIZE / 2 - x] = Snake;
		(SnakeBody).position[x] = (int) (GRIDSIZE / 2 - x); //typecast to prevent craziness
	}
	Game_RandomFruit(GameBoard);
	*ptrCurrentState = SnakeGame;
	return E_CFG_READY;
}

int Game_RandomFruit() {
	int bufferarray[GRIDSIZE];
	int buffernumber = 0;
	for (int i = 0; i < GRIDSIZE; i++) {
		if (GameBoard[i] == Fruit) {
			return E_ERROR;	//This function is not supposed to be called if a fruit already exists!
		} else if (GameBoard[i] == Wall || GameBoard[i] == Snake) {
		} // Simply do nothing if it encounters a wall or a snake object

		else if (GameBoard[i] == Empty) {
			bufferarray[buffernumber] = i; //Suitable for RNG Fruit
			buffernumber++;
		}

		else {
			return E_ERROR; //There's only supposed to be 4 types of game materials/objects, any unrecognized ones imply memory error, so quit with event E_ERROR
		}
	}

//Once magic is done with the for loop, here under we will do a RNG decision to spawn a fruit.
	srand(time(NULL)); // give seed to rand
	int randomnumber = rand() % buffernumber;
	GameBoard[bufferarray[randomnumber]] = Fruit; //Generate fruit at the randomly chosen empty square
	return E_CONT; //No errors, simply continue
}

int Game_CheckCollision(int *ptrCurrentState, int *ptrCurrentDirection,
		int *ptrCurrentSound, void (*ptrfuncLEDGrid)(int *ptrarrayLEDGrid)) {
	again:
	if (1) {}
	int futuresquare = (SnakeBody).position[0] + *ptrCurrentDirection;
	switch (GameBoard[futuresquare]) {
	case Wall:
		*ptrCurrentSound = SoundGameOver;
		*ptrCurrentState = StartMenu;
		Game_TopScoreSave();
		return E_SNAKE_COLLISION;

	case Snake:
		if (futuresquare == (SnakeBody).position[(SnakeBody).length - 1]) {
			*ptrCurrentSound = SoundSnakeMove;
			Game_MoveSnakeForward(futuresquare);
			return E_CONT;
		} else if (futuresquare == (SnakeBody).position[1]) {
			*ptrCurrentDirection = (SnakeBody).position[0]
					- (SnakeBody).position[1];
			goto again;
		} else {
			*ptrCurrentSound = SoundGameOver;
			*ptrCurrentState = StartMenu;
			Game_TopScoreSave();
			return E_SNAKE_COLLISION;
		}
		return E_ERROR; //undefined behaviour

	case Fruit:
		*ptrCurrentSound = SoundSnakeEat;
		Game_SnakeGrow(futuresquare);
		Game_RandomFruit();
		return E_CONT;

	case Empty:
		*ptrCurrentSound = SoundSnakeMove;
		Game_MoveSnakeForward(futuresquare);
		return E_CONT;
	}
	return E_ERROR; //undefined behaviour error
}

int Game_SnakeGrow(int futuresquare) {
	(SnakeBody).length++;
	for (int i = 0; i < (SnakeBody).length - 1; i++) {
		(SnakeBody).position[(SnakeBody).length - 1 - i] =
				(SnakeBody).position[(SnakeBody).length - 2 - i]; //shift snake position coordinates forward
	}
	(SnakeBody).position[0] = futuresquare;
	GameBoard[futuresquare] = Snake;
	return E_CONT;
}

int Game_MoveSnakeForward(int futuresquare) {
	GameBoard[(SnakeBody).position[(SnakeBody).length - 1]] = Empty;
	for (int i = 0; i < (SnakeBody).length - 1; i++) {
		(SnakeBody).position[(SnakeBody).length - 1 - i] =
				(SnakeBody).position[(SnakeBody).length - 2 - i]; //shift snake position coordinates forward
	}
	(SnakeBody).position[0] = futuresquare;
	GameBoard[futuresquare] = Snake;
	return E_CONT;
}

int Game_TopScoreSave()
{
	if((SnakeBody).length >254)
	{
		exit(E_ERROR); //undefined behaviour
	}
	FILE *topscorefile;
	topscorefile = fopen("topscore.txt", "r");
	int topscore = fgetc(topscorefile);
	fclose(topscorefile);
	if(topscore<(SnakeBody).length)
	{
		topscorefile = fopen("topscore.txt", "w");
		fputc((SnakeBody).length, topscorefile); //max snake size is 255!
		fclose(topscorefile);
	}
	return E_CONT;
}

