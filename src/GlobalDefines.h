/*
 * GlobalEnum.h
 *
 *  Created on: 30 Dec 2020
 *      Author: auxil
 */

#ifndef GLOBALDEFINES_H_
#define GLOBALDEFINES_H_
enum {
	Empty = 46, Wall, Snake = 71, Fruit = 82
};

enum {
	NonActive, Active
};

enum { //state enum
	StartMenu, Test, GameConfigure, SnakeGame, PauseMenu
};

enum {
	None, SoundSnakeMove, SoundSnakeEat, SoundStart, SoundGameOver, SoundPause
};

enum { //event enum
	E_SP_KEY = 8,
	E_SR_KEY = 13,
	E_LEFT_KEY = 37,
	E_RIGHT_KEY = 39,
	E_UP_KEY = 38,
	E_DOWN_KEY = 40,
	E_TEST_KEY = 84,
	E_CFG_READY,
	E_TEST_DONE,
	E_CONT,
	E_SNAKE_COLLISION,
	E_ERROR
};

#define GRIDLENGTH (21) // any number as long as it's high enough =>9 and uneven!
#define GRIDSIZE (GRIDLENGTH*GRIDLENGTH) // don't touch this
#define SNAKESIZE (4) //4 is usually used as a starting size
#define PERIOD (400) // GAME SPEED PERIOD IN MILLISECONDS

enum {
	Right = 1, Down = GRIDLENGTH, Left = -1, Up = -GRIDLENGTH
};

#endif /* GLOBALDEFINES_H_ */
