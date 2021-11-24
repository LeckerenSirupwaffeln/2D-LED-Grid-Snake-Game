#ifndef SNAKEGAME_H_
#define SNAKEGAME_H_

typedef struct {
	int length;
	int position[GRIDSIZE];
} StructSnakeBody;

extern StructSnakeBody SnakeBody;
extern int GameBoard[GRIDSIZE];

int Game_Snake(int *ptrCurrentState, int *ptrCurrentDirection, int *ptrCurrentSound, void (*ptrfuncLEDGrid)(int *ptrarrayLEDGrid));
int Game_CFG(int *ptrCurrentState);
int Game_RandomFruit();
int Game_CheckCollision(int *ptrCurrentState, int *ptrCurrentDirection, int *ptrCurrentSound,
		void (*ptrfuncLEDGrid)(int *ptrarrayLEDGrid));
int Game_SnakeGrow(int futuresquare);
int Game_MoveSnakeForward(int futuresquare);
int Game_TopScoreSave();

#endif /* SNAKEGAME_H_ */
