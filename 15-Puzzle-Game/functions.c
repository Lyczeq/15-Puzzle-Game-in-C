/** @file */
#include <stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>

#include"functions.h"
#include"structures.h"

listElement* create_linked_list()
{
	listElement* head = NULL;
	listElement* temp = NULL;
	listElement* p = NULL;
	srand(time(NULL));

	int randomArray[16];

	int i, j, bufor;

	for (i = 0; i < 16; i++)
		randomArray[i] = i;
	for (i = 0; i < 16; i++)
	{
		j = (rand() % 15) + 1;
		bufor = randomArray[i];
		randomArray[i] = randomArray[j];
		randomArray[j] = bufor;
	}
	for (int i = 0; i <= 15; i++)
	{
		temp = (listElement*)malloc(sizeof(listElement));
		temp->number = randomArray[i];
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			p = head;
			while (p->next != NULL)
				p = p->next;
			p->next = temp;
		}
	}
	return head;
}

int** create_game_board(listElement* head)
{
	listElement* temp = head;

	int** game_board = calloc(NROWS, sizeof(int*));
	for (int r = 0; r < NROWS; r++)
	{
		game_board[r] = calloc(NCOLUMNS, sizeof(int));
	}

	for (int r = 0; r < NROWS; r++)
	{
		for (int c = 0; c < NCOLUMNS; c++)
		{
			game_board[r][c] = temp->number;
			temp = temp->next;
		}
	}

	return game_board;
}

void show_game_details()
{
	printf("----------------------------FIFTEEN PUZZLE GAME----------------------------\n");
	printf(" The goal of the game is to order the numbers from 1 to 15 by rows and leave last space blank.\n");
}

void print_game_board(int** game_board)
{
	printf("\n");
	for (int r = 0; r < NROWS; r++)
	{
		for (int c = 0; c < NCOLUMNS; c++)
		{
			if (game_board[r][c] == 0)
				printf(" %2s ", "");
			else
				printf(" %2d ", game_board[r][c]);
		}
		printf("\n");
	}
}

enum Move print_move_and_get_move(int** game_board, listElement** head)
{
	int nextMove;
	int row = 0, column = 0;
	for (;;)
	{
		for (int r = 0; r < NROWS; r++)
		{
			for (int c = 0; c < NCOLUMNS; c++)
			{
				if (game_board[r][c] == 0)
				{
					row = r;
					column = c;
				}
			}
		}
		if (row + 1 >= 0 && row + 1 < NROWS)
			printf("Enter W to move %d up. ", game_board[row + 1][column]);
		if (row - 1 >= 0 && row - 1 < NROWS)
			printf("Enter S to move %d down. ", game_board[row - 1][column]);
		if (column + 1 >= 0 && column + 1 < NROWS)
			printf("Enter A to move %d left. ", game_board[row][column + 1]);
		if (column - 1 >= 0 && column - 1 < NROWS)
			printf("Enter D to move %d right. ", game_board[row][column - 1]);
		printf("Enter Q to Quit Game:");
		nextMove = getchar();
		while (getchar() != '\n');
		switch (nextMove)
		{
		case 'w': return moveUp;
		case 's': return moveDown;
		case 'a': return moveLeft;
		case 'd': return moveRight;
		case 'q':
		{ delete_game_board(game_board);
		delete_linked_list(head);
		exit(EXIT_SUCCESS); }
		}
	}
}

int** board_update(enum Move move, int** game_board)
{
	int row = 0;
	int column = 0;
	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };

	int moveHorizontal = dx[move];
	int moveVertical = dy[move];
	for (int r = 0; r < NROWS; r++)
	{
		for (int c = 0; c < NCOLUMNS; c++)
		{
			if (game_board[r][c] == 0)
			{
				row = r;
				column = c;
			}
		}
	}
	int updatedRow = row + moveHorizontal;
	int updatedColumn = column + moveVertical;

	if (updatedRow >= 0 && updatedRow < NROWS && updatedColumn >= 0 && updatedColumn < NCOLUMNS)
	{
		game_board[row][column] = game_board[updatedRow][updatedColumn];
		game_board[updatedRow][updatedColumn] = 0;
	}

	return game_board;
}

bool is_game_finished(int** game_board)
{
	int counter = 0;
	int iterator = 1;
	bool stop = false;
	const int win = 15;

	for (int r = 0; (r < NROWS) && stop != true; r++)
	{
		for (int c = 0; (c < NCOLUMNS) && stop != true; c++)
		{
			if (game_board[r][c] == iterator)
			{
				counter++;
				iterator++;
			}
			else stop = true;
		}
	}

	if (game_board[NROWS - 1][NCOLUMNS - 1] == 0 && counter == win)
		return true;
	else return false;
}

void delete_game_board(int** game_board)
{
	for (int r = 0; r < NROWS; r++)
		free(game_board[r]);
	free(game_board);
}

void delete_linked_list(listElement** head)
{
	listElement* current = *head;
	listElement* next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}