/** @file */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<stdio.h>
#include<stdbool.h >
#include "structures.h"

/**
Function creates a linked list and fill it with the numbers from 0 to 15 in a random sequence.
@return Created linked list filled with the numbers from 0 to 15 in a random sequence.
*/
listElement* create_linked_list();

/**
Function creates a two-dimensional array 4x4 that is filled with the numbers from sent linked list.
@param head Head of the linked list.
@return Two dimensional array 4x4 that is filled with the numbers from sent linked list.
*/
int** create_game_board(listElement* head);

/**
Function shows the title and rules of the game.
*/
void show_game_details();

/**
Function prints sent game-board on the screen.
@param board Two-dimensional array 4x4 that is the board of the game.
*/
void print_game_board(int** game_board);

/**
Function prints the list of the possbile moves and receives a char from the user of his next move. If the user chooses to quit the game, function deletes the 2D array, the linked list and then it closes the application.
@param game_board Two-dimensional array 4x4, which is deleted if the user chooses to quit the game.
@param head Linked list, which is deleted if the user chooses to quit the game.
@return Next user's move.
*/
enum Move print_move_and_get_move(int** game_board, listElement** head);

/**
Function updates the game board based on user's next move.
@param move Next user's move.
@param game_board Two-dimensional array 4x4 that will be updated based on user's next move.
@return Updated board
*/
int** board_update(enum Move move, int** game_board);

/**
Function checks if the game board is ordered according to the game's rules.
@param game_board Two dimensional 4x4 Game board that is sent to check if it is well-ordered.
@return True if the game board is well-ordered, False if it's not.
*/
bool is_game_finished(int** game_board);

/**
Function deletes the two-dimensional array 4x4 that is the game board.
@param game_board Two-dimensional array 4x4 that is the game board.
*/
void delete_game_board(int** board);

/**
Function  deletes the linked list.
@param head Head of the linked list.
*/
void delete_linked_list(listElement** head);
#endif