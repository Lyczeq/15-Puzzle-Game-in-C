/** @file */

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<time.h>

#include"functions.h"
#include"structures.h"

int main()
{
	listElement* HEAD = NULL;
	HEAD = create_linked_list();
	int** game_board = create_game_board(HEAD);
	int move_cunter = 0;

	show_game_details();
	do {
		print_game_board(game_board);
		enum Move nextMove = print_move_and_get_move(game_board, &HEAD);
		move_cunter++;
		game_board = board_update(nextMove, game_board);
	} while (!is_game_finished(game_board));

	print_game_board(game_board);
	printf(" Congratulations! You needed %d moves to win the game!", move_cunter);

	delete_game_board(game_board);
	delete_linked_list(&HEAD);
}