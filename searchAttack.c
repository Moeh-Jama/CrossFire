/*
 * 		searchAttack.c
 *
 *  	Created on: Apr 10, 2017
 *      Author: Eoin Leonard & Mohamed Jama.
 */

#include <stdio.h>
#include "controlFile.h"
int board_Size = 3;

	/*
		in order to check if a slot contains a player we first need the location of the slot and the player number
		--As of now a slot contains the values of the column and rows.
		it also points to all adjecent slots around it.
		Along with that a slot also contains the slot type, Hill, City, Ground.
		And finally a slot contains the player identifer.
	*/
	
	
/*int check_More_Than_One(int player_identifier)
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
	
}*/
void check_adjecent_Slots(struct players * attacker){
	//look for the current Slot using player_identifer.

	//Then search for adjecent slots.

	//if there is more than one user found, ask the user to choose. Use current_row & current_column
	//printf("\n%d---(%d, %d)\t", attacker->)

}

int distantAttack(struct slot * victim)
{

	return 0;
}

int getDistance(struct slot*attacker, struct slot*attacked)
{
	printf("Row %d\tColumn %d\n", attacker->row,attacker->column);
	printf("Row %d\tColumn %d\n", attacked->row,attacked->column);
	int result ,column_result, row_result;
	if(attacker->row >= attacked->row)
	{
		row_result = (attacker->row) - (attacked->row);
		printf("row_Result1st: %d\n", row_result);
	}
	else if(attacked->row >= attacker->row)
	{
		row_result = (attacked->row) - (attacker->row);
		printf("row_Result2nd: %d\n", row_result);
	}

	if(attacker->column >= attacked->column)
		{
		column_result = (attacker->column) - (attacked->column);
		printf("column_Result2nd: %d\n", column_result);
		}
	else if(attacked->column >= attacker->column)
		{
			column_result = (attacked->column) - (attacker->column);
			printf("column_Result2nd: %d\n", column_result);
		}


	result = row_result+column_result;
	printf("Row %d\tColumn %d\n",row_result,column_result);
	return result;
}

struct slot * reachDesiredElement(int row, int column, struct slot * initialSlot){

	bool found = false;
	//current slot
	struct slot * currentSlot = initialSlot;

	printf("\nFunction reachDesiredElement invoked\n");

	//prints the column and the row of the initial slot from which the search starts
	printf("Initial slot (%d, %d) -> \n",initialSlot->row,initialSlot->column);


	//while the slot is not found
	while(found == false){


		//if the row of the current slot is > of the row of the desired slot,
		//we move up
		if(currentSlot->row > row){
			//the current slot now points to the slot one row up
			currentSlot = currentSlot->up;
			//prints the column and the row of the current slot
			printf("up Current slot (%d, %d) -> \n",currentSlot->row,currentSlot->column);
		}
		//if the row of the current slot is < of the row of the desired slot,
		//we move down
		if(currentSlot->row < row){
			//the current slot now points to the slot one row down
			currentSlot = currentSlot->down;
			//prints the row and the column of the current slot
			printf("down Current slot (%d, %d) -> \n",currentSlot->row,currentSlot->column);

		}
		//if the column of the current slot is > of the column of the desired slot,
		//we move left
		if(currentSlot->column > column){

			//the current slot now points to the slot one column left
			currentSlot = currentSlot->left;
			//prints the row and the column of the current slot
			printf("left Current slot (%d, %d) -> \n",currentSlot->row,currentSlot->column);
		}

		//if the column of the current slot is < of the column of the desired slot,
		//we move right
		if(currentSlot->column < column){

			//the current slot now points to the slot one column right
			currentSlot = currentSlot->right;
			//prints the row and the column of the current slot
			printf("right Current slot (%d, %d) -> \n",currentSlot->row,currentSlot->column);

		}
		//if the current slot is at a column and a row equal to the desired column and row, respectively
		// we found the slot
		if(currentSlot->column == column && currentSlot->row == row){
			printf("Found\n");
			found = true;

		}

	}
	//returns the found slot
	return currentSlot;
}

void near_Attack(struct players * attacker)
{
	/*
	 * This function only tells us the adjecent players to the attacker.
	 *
	 */

	//printf("\n%d---(%d, %d)\t", attacker->place->player_Identifier, attacker->place->row, attacker->place->column);
	if(attacker->place->row!=0 && attacker->place->up->player_Identifier!= -1)
	{
		printf("%s We have found %s above you!\n",cases[attacker->player_Identifier -20].name_one, cases[attacker->place->up->player_Identifier -20].name_one);
		printf("%d found Over %d!\n", attacker->place->up->player_Identifier,attacker->player_Identifier );
	}
	if(attacker->place->row!=6 && attacker->place->down->player_Identifier !=-1)
	{
		printf("%s We have found %s under you!\n",cases[attacker->player_Identifier -20].name_one, cases[attacker->place->down->player_Identifier -20].name_one);
		printf("%d found Under %d!\n", attacker->place->down->player_Identifier,attacker->player_Identifier );
	}
	if(attacker->place->column!=0 && attacker->place->left->player_Identifier !=-1)
	{
		printf("%s We have found  %s to the left you!\n",cases[attacker->player_Identifier -20].name_one, cases[attacker->place->left->player_Identifier -20].name_one);
		printf("%d found to the left of %d!\n",attacker->place->left->player_Identifier,attacker->player_Identifier );
	}
	if(attacker->place->column!=6 && attacker->place->right->player_Identifier !=-1){
		printf("%s We have found  %s to the right of you!\n",cases[attacker->player_Identifier -20].name_one, cases[attacker->place->right->player_Identifier -20].name_one);
		printf("%d found to the right of %d!\n", attacker->place->right->player_Identifier,attacker->player_Identifier );
	}




	/*
		What We Have At This Point: Location, Both Player Identifiers, and are able to
		access both players attributes.

		Perform attacking here, We already know the*/

}




/*void magic_Attack(int attacking, int attacked){
	//for this search throughtout the players and find the living ones, then ask the player to
	//choose whome to attack.
}*/



