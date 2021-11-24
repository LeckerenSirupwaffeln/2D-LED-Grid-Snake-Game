/*
 * Menu.h
 *
 *  Created on: 7 Jan 2021
 *      Author: auxil
 */

#ifndef MENU_H_
#define MENU_H_

int Game_StartMenu(int *ptrCurrentSound, int *ptrCurrentState,
		void (*ptrfuncLEDGrid)(int *ptrarrayLEDGrid));
int Game_PauseMenu(int *ptrCurrentSound, int *ptrCurrentState);

#endif /* MENU_H_ */
