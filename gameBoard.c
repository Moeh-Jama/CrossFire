/*
 * gameBoard.c
 *
 *  Created on: Apr 8, 2017
 *      Author: Mohamed Jama & Eoin Leonard.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controlFile.h"
//void createBoards(int board_Size, struct slot **upLeft, struct slot **upRight, struct slot **downRight, struct slot **downLeft);

void createBoards(int board_Size, struct slot **upLeft, struct slot **upRight, struct slot **downRight, struct slot **downLeft){
	//Here we create the boards.
	board = malloc(board_Size * sizeof(struct slot*));

	srand(time(NULL));
	for(int i=0; i<board_Size; i++)
	{
		board[i] = malloc(board_Size * sizeof(struct slot));
		for(int k=0; k<board_Size; k++)
		{
			board[i][k].player_Identifier = -1;
			board[i][k].row = i;
			board[i][k].column =k;
			int randomPlace = 5;
			do{
				randomPlace = rand()%3;
			}while(randomPlace>2 || randomPlace<0);
			board[i][k].slotType = randomPlace;
			//printf("(%d, %d)\n",board[i][k].row, board[i][k].column);
		}
	}

	//Pointing the edges of the board to their neighbors
	for(int i=1; i<board_Size-1; i++)
	{

		//Top Edge
		board[0][i].right = &board[0][i+1];
		board[0][i].left = &board[0][i-1];
		board[0][i].down = &board[i][0];
		board[0][i].up = NULL;
		//Bottom Edge
		board[board_Size-1][i].right = &board[board_Size-1][i+1];
		board[board_Size-1][i].left = &board[board_Size-1][i-1];
		board[board_Size-1][i].up = &board[board_Size-2][i];

		//Right Edge
		board[i][0].right = &board[i][1];
		board[i][0].left = NULL;
		board[i][0].up = &board[i+1][0];
		board[i][0].down = &board[i-1][0];

		//Left Edge
		board[i][board_Size-1].right = NULL;
		board[i][board_Size-1].left = &board[board_Size-1][board_Size-2];
		board[i][board_Size-1].up = &board[i-1][board_Size-1];
		board[i][board_Size-1].down = &board[i+1][board_Size-1];

		//Inner Board Slots
		for(int k=1; k<board_Size-1; k++)
		{
			board[i][k].right = &board[i][k+1];
			board[i][k].left = &board[i][k-1];
			board[i][k].up = &board[i-1][k];
			board[i][k].down = &board[i+1][k];
		}

	}
	//Top Left.
	board[0][0].right = &board[0][1];
	board[0][0].down = &board[1][0];
	//Top Right.
	board[0][board_Size-1].left = &board[0][board_Size-2];
	board[0][board_Size-1].down = &board[1][board_Size-1];
	//Down Right.
	board[board_Size-1][board_Size-1].up = &board[board_Size-2][board_Size-1];
	board[board_Size-1][board_Size-1].left = &board[board_Size-1][board_Size-2];
	//Down Left.
	board[board_Size-1][0].right = &board[board_Size-1][1];
	board[board_Size-1][0].up = &board[board_Size-2][0];

	//All Four Corner of the board are taken by the struct slots **Values.
	*upLeft = &board[0][0];
	*upRight = &board[0][board_Size-1];
	*downRight = &board[board_Size-1][board_Size-1];
	*downLeft = &board[board_Size-1][0];

		//Print the results
	printf("\n");
	for(int i=0; i<board_Size; i++)
		{

			for(int k=0; k<board_Size; k++)
			{
				printf("(%d, %d)\t", board[i][k].row, board[i][k].column);
			}
			printf("\n");
		}
}

