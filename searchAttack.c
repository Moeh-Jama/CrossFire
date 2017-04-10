/*
 * searchAttack.c
 *
 *  Created on: Apr 10, 2017
 *      Author: Eoin Leonard & Mohamed Jama.
 */

#include <stdio.h>
#include "controlFile.h"

	/*
		in order to check if a slot contains a player we first need the location of the slot and the player number
		--As of now a slot contains the values of the column and rows.
		it also points to all adjecent slots around it.
		Along with that a slot also contains the slot type, Hill, City, Ground.
		And finally a slot contains the player identifer.
	*/
	
	
int check_More_Than_One(int player_identifier)
{
	//This function will be called if
	//quickly check if there is a player within the slot.

	if(There_Is_another_player == 1)
	{
		return  other_player_identifer.	//here we return the other players identifier.
	}
	else{
		return -1;		//if there is no player the we return -1.
	}
	
}
int check_adjecent_Slots(int player_identifer){
	//look for the current Slot using player_identifer.

	//Then search for adjecent slots.

	//if there is more than one user found, ask the user to choose. Use current_row & current_column

	int numberOfFoundPlayers=0;
	int right=0; left=0; top=0; bottom=0;
	if(board[current_row][current_column+1].player_identifier!=-1)
	{
		printf("Found a player on the Right!\n");
		right=1;
		numberOfFoundPlayers++;
	}
	if(board[current_row][current_column-1].player_identifier!=-1){
		printf("Found a player on the Left!\n");
		left=1;
		numberOfFoundPlayers++;
	}
	if(board[current_row+1][current_column].player_identifier!=-1){
		printf("Found a player on the Top!\n");
		top=1;
		numberOfFoundPlayers++;
	}
	if(board[current_row-1][current_column].player_identifier!=-1){
		printf("Found a player on the Bottom!\n");
		bottom=1;
		numberOfFoundPlayers++;
	}


	if(numberOfFoundPlayers >1)
	{
		printf("Please choose which of the players to attack\n");
		if(right>0)
		{
			printf("1.Right!\n");
		}
		if(left>0){
			printf("2.Left!\n");
		}
		if(top>0){
			printf("3.Top\n");
		}
		if(bottom>0){
			printf("4.Bottom\n");
		}
		int attack_Choice;

		scanf("%d", &attack_Choice);
		if(attack_Choice==1 && right>0){
			//Here We will allow user to pic that player identifers.
			return board[current_row][current_column+1].player_identifier;
		}
		else if(attack_Choice==2 && left>0)
		{
			return board[current_row][current_column-1].player_identifier;
		}
		else if(attack_Choice==3 && top>0)
		{
			return board[current_row+1][current_column].player_identifier;
		}
		else if(attack_Choice==4 && bottom>0)
		{
			return board[current_row-1][current_column].player_identifier;
		}
		else{
			printf("I'm Sorry but you cannot make that choice try again Please.\n");
			int value = check_adjecent_Slots(player_identifer);
			return value;
		}
	}
	else{
		return -1;
	}
}
void near_Attack(int player_identifier, int other_player_identifer, struct slot*)
{
	/*
		for this function we would already have both the player identifiers.
	*/

	int slot_row, slot_column;
	for(int i=0; i<board_Size; i++)
	{

		for(int k=0; k<board_Size; k++)
		{

			if(player_identifier == board[i][k].player_identifier)
			{

				i=slot_row;
				k=slot_column;
			}
		}
	}




	/*
		What We Have At This Point: Location, Both Player Identifiers, and are able to
		access both players attributes.

		Perform attacking here, We already know the 
	*/
}


void distant_Attack(int attacking, int attacked)
{
	//Do a recursion function for near & distant Attacks.
	//Then get the player to choose whome to attack.
}


void magic_Attack(int attacking, int attacked){
	//for this search throughtout the players and find the living ones, then ask the player to
	//choose whome to attack.
}



