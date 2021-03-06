/** @file */
#ifndef STRUCTURES_H
#define STRUCTURES_H

#include<stdio.h>
/**Enumerative type used to choose next user's move and update the game board.*/
enum Move {
	moveUp = 0,		///< If it's 0, the function called "board_update" moves up a number below the blank space.
	moveDown = 1,	///< If it's 1, the function called "board_update" moves down a number above the blank space.
	moveLeft = 2,	///< If it's 2, the function called "board_update" moves left a number on the right of the blank space.
	moveRight = 3,	///< If it's 3, the function called "board_update" moves right a number on the left of the blank space.
};

#define _CRT_SECURE_NO_WARNINGS
#define NROWS 4
#define NCOLUMNS 4

/*Element of the linked list.*/
typedef struct listElement
{
	int number;					///<The number stored in the linked list element.
	struct listElement* next;	///<The pointer on the next list element.
} listElement;
#endif