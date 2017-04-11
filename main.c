/*
 * main.c
 *
 *  Created on: Apr 10, 2017
 *      Author: Eoin Leonard & Mohamed Jama
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controlFile.h"
void printBoard(){
	//Printing out Board Contents.
	int board_Size=7;
	printf("\n--------------------------------------------------------\n");
	for(int i=0; i<board_Size; i++)
	{
		for(int k=0; k<board_Size; k++)
		{
			if(board[i][k].player_Identifier==-1){
				printf("|%d, %d|\t", board[i][k].row, board[i][k].column);
			}
			else{
				printf("|%s,i|\t", cases[board[i][k].player_Identifier].name_one);
			}
		}
		printf("\n");
	}
	printf("--------------------------------------------------------\n");
	
}
int main(void)
{
	setbuf(stdout,NULL);
	srand(time(NULL));
	printf("The Main.c");
	struct slot *upLeft;
	struct slot *upRight;
	struct slot *downRight;
	struct slot *downLeft;

	int board_Size = 7;


	//Temporary Character Creation.
	createCharacters();
	//here the slots are created along with the slot type, i.e. Hill, City Ground.
	createBoards(board_Size ,&upLeft, &upRight, &downLeft, &downRight);
	print_players();
	//Placing players into Boards.
	for(int i=0; i<player_number; i++){
		int random_row, random_column;
		//Randomly placing players in a slot, using rand() with the rows ad columns.
		do{
			random_column = rand()%board_Size;
			random_row = rand()%board_Size;
		}while((random_row<0 && random_column<0) || board[random_row][random_column].player_Identifier>=0);	//make sure board is not occupied.  && board[random_row][random_column].player_identifier !=-1
		board[random_row][random_column].player_Identifier = cases[i].player_Identifier;
		cases[i].place = &board[random_row][random_column];
		printf("(%d, %d -- %d)\n",random_row, random_column, board[random_row][random_column].player_Identifier);
	}
	//Printing out 
	printBoard();

	//Looking for adjacent.
	for(int i=0; i<player_number; i++)
	{
		printf("Current Player: (%d,%d)\n",cases[i].place->row,cases[i].place->column);
		near_Attack(&cases[i]);
		//distantAttack(cases[i].place);
	}
	printBoard();


	/*
	 * runWhile(players_with_Health>1){
	 * 		call functions....
	 * }
	 *
	 *	printf("Player %s %s Is the Last Standing", player[i][i].firstName, player[i][i].lastName);
	 *
	 */

	return 0;
}


