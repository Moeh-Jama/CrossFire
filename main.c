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
				printf("|%s|\t", cases[board[i][k].player_Identifier-20].name_one);
			}
		}
		printf("\n");
	}
	printf("--------------------------------------------------------\n");
	
}
/*int getOptions(struct players *mover)
{
	if(mover->place-> != NULL)
}*/
int main(void)
{
	setbuf(stdout,NULL);
	srand(time(NULL));
	struct slot* currSlot = NULL;
	struct slot *foundSlots;
	bool explored[BOARD_SIZE][BOARD_SIZE];
	int count =0;
	printf("\tWelcome TO CrossFire\n");
	struct slot *upLeft;
	struct slot *upRight;
	struct slot *downRight;
	struct slot *downLeft;

	int board_Size = 7;

	//char character[12] = "abcdefghijk";
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
	//near_Attack(&cases[i]);
	//distantAttack(cases[i].place->right);
	for(int i=0; i<player_number; i++)
	{
		printf("Current Player: (%d,%d)\n",cases[i].place->row,cases[i].place->column);
<<<<<<< HEAD

		printf("Choose a move option:\n");
		//Get Options of movements function.
		int type;

		if(cases[i].place==upLeft)
		{
			type = 0;
		}
		if(cases[i].place==downLeft)
		{
			type =3;
		}
		if(cases[i].place==upRight)
		{
			type=2;
		}
		if(cases[i].place==downRight)
		{
			type = 4;
		}
		if(cases[i].place->up==NULL)
		{
			type=5;
		}

		printf("1.Up\n2.Down\n3.Right\n4.Left\n");
		int choice;
		scanf("%d", &choice);

		//if(choice=1 && (cases[i].place==upLeft || cases[i].place==upRight ||cases[i].place->up==NULL )

		switch(choice)
		{
			case 1:{
				//Moving UP.
				int row_n, column_n;
				row_n = cases[i].place->row;
				column_n = cases[i].place->column;
				printf("%s\n(%d, %d)\n",cases[i].name_one, cases[i].place->row, cases[i].place->column);
				cases[i].place->player_Identifier=-1;
				cases[i].place = board[row_n][column_n].up;
				cases[i].place->player_Identifier=i+20;
				printf("%s\n(%d, %d)\n",cases[i].name_one, cases[i].place->row, cases[i].place->column);
				break;
			}
			case 2:{
				//Moving Down.
				int row_n, column_n;
				row_n = cases[i].place->row;
				column_n = cases[i].place->column;
				printf("%s\n(%d, %d)\n",cases[i].name_one, cases[i].place->row, cases[i].place->column);
				cases[i].place->player_Identifier=-1;
				cases[i].place = board[row_n][column_n].down;
				cases[i].place->player_Identifier=i+20;
				printf("%s\n(%d, %d)\n",cases[i].name_one, cases[i].place->row, cases[i].place->column);
				break;
			}
			case 3:{
				//Move Right
				int row_n, column_n;
				row_n = cases[i].place->row;
				column_n = cases[i].place->column;
				printf("%s\n(%d, %d)\n",cases[i].name_one, cases[i].place->row, cases[i].place->column);
				cases[i].place->player_Identifier=-1;
				cases[i].place = board[row_n][column_n].right;
				cases[i].place->player_Identifier=i+20;
				printf("%s\n(%d, %d)\n",cases[i].name_one, cases[i].place->row, cases[i].place->column);
				break;
			}
			case 4:{
				//Move Left.
				int row_n, column_n;
				row_n = cases[i].place->row;
				column_n = cases[i].place->column;
				printf("%s\n(%d, %d)\n",cases[i].name_one, cases[i].place->row, cases[i].place->column);
				printf("Next: (%d,%d)\n", board[row_n][column_n].left->row, board[row_n][column_n].left->column);
				cases[i].place->player_Identifier=-1;
				cases[i].place = board[row_n][column_n].left;
				cases[i].place->player_Identifier=i+20;
				printf("%s\n(%d, %d)\n",cases[i].name_one, cases[i].place->row, cases[i].place->column);
				break;
			}
			default:{
				printf("Error has occurred\n");
				exit(0);
			}
		}
	}


	printBoard();
	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE;j++){
			explored[i][j] = false;
		}
	}
	//A method of getting the distance between two characters.
	int result;
	for(int i=0; i<6;i++)
	{
			//getDesiredElement(BOARD_SIZE, &cases[i].place->row,&cases[i].place->column);
		for(int j=0;j<6;j++)
		{
			//Since we get the distance between two characters we can now filter the users beyond our scope. less than 2 and greater than 4.
			result = getDistance(cases[i].place, cases[j].place);
			printf("Between (%d,%d)-(%d,%d): RESULT: %d\n",cases[i].place->row,cases[i].place->column,cases[j].place->row,cases[j].place->column, result);
		}


=======
		near_Attack(&cases[i]);
		//distantAttack(cases[i].place);
>>>>>>> origin/master
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


