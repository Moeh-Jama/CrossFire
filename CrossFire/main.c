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
				printf("|%d, %d|\t", board[i][k].row, board[i][k].column);
		}
		printf("\n");
	}
	printf("--------------------------------------------------------\n");
	
}
void movement(struct players * current_Player){
	//This functions  takes care of the movement operations.
	printf("Current Player: (%d,%d)\n",current_Player->place->row,current_Player->place->column);
	printf("Choose a move option:\n");
	if(current_Player->place->up !=NULL)
	{
		printf("1.Up [%d, %d]-Terraine : ",current_Player->place->up->row,current_Player->place->up->column);
		terraine_type(current_Player->place->up->slotType);
	}
	else{
		printf("1.Up NULL");
	}
	if(current_Player->place->down !=NULL)
		{
		printf("\n2.Down [%d, %d]-Terraine : ",current_Player->place->down->row,current_Player->place->down->column);
			terraine_type(current_Player->place->down->slotType);
		}
		else{
			printf("\n2.Down NULL");
		}
	if(current_Player->place->right !=NULL)
		{
			printf("\n3.Right [%d, %d]-Terraine : ",current_Player->place->right->row,current_Player->place->right->column);
			terraine_type(current_Player->place->right->slotType);
		}
		else{
			printf("\n3.Right NULL");
		}
	if(current_Player->place->left !=NULL)
		{
		printf("\n4.Left [%d,%d]-Terraine : ",current_Player->place->left->row,current_Player->place->left->column);
		terraine_type(current_Player->place->left->slotType);
		}
		else{
			printf("\n4.Left NULL");
		}
	int choice;
	scanf("%d", &choice);
	while((current_Player->place->up== NULL && choice ==1) || (current_Player->place->down ==NULL && choice ==2) || (current_Player->place->right == NULL && choice==3) || (current_Player->place->left == NULL && choice==4))
	{
		printf("Invalid Entry, Please Try Again\n");
		printf("1.Up\n2.Down\n3.Right\n4.Left\nEnter: ");
		scanf("%d", &choice);
	}
	//if(choice=1 && (cases[i].place==upLeft || cases[i].place==upRight ||cases[i].place->up==NULL )
	switch(choice)
	{
	case 1:{
		//Moving UP.
		current_Player->place->player_Identifier=-1;
		current_Player->place = current_Player->place->up;
		current_Player->place->player_Identifier=current_Player->player_Identifier;
		moded_Capabilities(current_Player);
		break;
	}
	case 2:{
		//Moving Down.
		current_Player->place->player_Identifier=-1;
		current_Player->place = current_Player->place->down;
		current_Player->place->player_Identifier=current_Player->player_Identifier;
		moded_Capabilities(current_Player);
		break;
	}
	case 3:{
		//Move Right
		current_Player->place->player_Identifier=-1;
		current_Player->place = current_Player->place->right;
		current_Player->place->player_Identifier=current_Player->player_Identifier;
		moded_Capabilities(current_Player);
		break;
	}
	case 4:{
		//Move Left.
		current_Player->place->player_Identifier=-1;
		current_Player->place = current_Player->place->left;
		current_Player->place->player_Identifier=current_Player->player_Identifier;
		moded_Capabilities(current_Player);
		break;
	}
	default:{
		printf("Error has occurred\n");
		exit(0);
	}
	}
}
int main(void)
{
	setbuf(stdout,NULL);
	srand(time(NULL));
	printf("\tWelcome To CrossFire\n");
	struct slot *upLeft;
	struct slot *upRight;
	struct slot *downRight;
	struct slot *downLeft;
	int board_Size = 7;
	createCharacters();
	//here the slots are created along with the slot type, i.e. Hill, City Ground.
	createBoards(board_Size ,&upLeft, &upRight, &downLeft, &downRight);
	//Placing players into Boards.
	int players_That_Are_Living[player_number];
	int k=0;
	for(int i=0; i<player_number; i++){
		int random_row, random_column;
		players_That_Are_Living[i]=i;
		//Randomly placing players in a slot, using rand() with the rows ad columns.
		do{
			random_column = rand()%board_Size;
			random_row = rand()%board_Size;
		}while(random_row<0 && random_column<0);	//make sure board is not occupied.  && board[random_row][random_column].player_identifier !=-1  || board[random_row][random_column].player_Identifier>=0)
		board[random_row][random_column].player_Identifier = cases[i].player_Identifier;
		cases[i].place = &board[random_row][random_column];
		board[random_row][random_column].number_Of_Players++;
		moded_Capabilities(&cases[i]);
		//printf("(%d, %d -- %d)\n",random_row, random_column, board[random_row][random_column].player_Identifier);
		k=0;
	}
	//Here The Actual Game Will begin.
	players_With_Health=player_number;
	int round=0;
	while(players_With_Health>1){
		//round=0;
		printBoard();
		print_players();
		printf("**Current Round %d **\n", ++round);
		for(int i=0;i<player_number;i++)
		{
			//Make Sure that no dead player gets to continue in the game.
			if(cases[i].health <= 0)
			{//searching for player who is alive
				while(cases[i].health<=0 && i<player_number-1)
				{
					i++;
				}
			}
			printf("%s %s choose one of the following actions to perform\n1.Move slots\n2.An Attack\n3. Exit Game\nEnter Choice", cases[i].name_one, cases[i].name_two);
			int gameChoice;
			scanf("%d", &gameChoice);
			while(gameChoice<1 || gameChoice>3)
			{
				printf("Invalid choice Try Again!\n%s, %s choose one of the following actions to perform\n1.Move slots\n2.An Attack\n3. Exit Game\nEnter Choice", cases[i].name_one, cases[i].name_two);
				int gameChoice;
				scanf("%d", &gameChoice);
			}
			switch(gameChoice)
			{
			case 1:{
				movement(&cases[i]);
				break;
			}
			case 2:{
				attack_Menu(&cases[i]);
				break;
			}
			case 3:{
				cases[i].health=0;
				printf("Player %s %s Has Left The Game\n", cases[i].name_one, cases[i].name_two);
				players_With_Health--;
				break;
			}
			default:{
				printf("Uncaught error. Game choice was less than 1 or greater than 3\nTerminating game");
				exit(0);
			}
		}
		}
	}

	for(int i=0; i<player_number;i++)
	{
		if(cases[i].health >0)
		{
			printf("Congratulations %s %s You Have Won the Game!", cases[i].name_one, cases[i].name_two);
			printf("\nGame Terminated\n");
			exit(0);
		}
	}
	if(players_With_Health==0)
	{
		printf("Everyone has left the game\nNo Winner.");
	}
	printBoard();
	return 0;
}


