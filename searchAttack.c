/*
 * searchAttack.c
 *
 *  Created on: Apr 10, 2017
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
	//USe recursion in this case.
	printf("{{{{%d}}}}\n", victim->row);
	if(victim->player_Identifier !=19)
	{
		printf("PLayer: (%d)\t", victim->player_Identifier);
		printf("Found Player at (%d, %d)\n", victim->row, victim->column);
		return victim->column;
	}
	else
	{
		if(victim->column<6)
		{
			return distantAttack(victim->right);
		}
		else if(victim->column==6)
		{
			return distantAttack(victim->down->column=0);
		}
	}
	return 0;
}


/*void near_Attack(struct players * attacker)
{


	printf("\n%d---(%d, %d)\t", attacker->place->player_Identifier, attacker->place->row, attacker->place->column);
	if(attacker->place->row!=0 && attacker->place->up->player_Identifier>19)
	{
		printf("%d found Over %d!\n", attacker->place->up->player_Identifier,attacker->player_Identifier );
	}
	if(attacker->place->row!=6 && attacker->place->down->player_Identifier >19)
	{
		printf("%d found Under %d!\n", attacker->place->down->player_Identifier,attacker->player_Identifier );
	}
	if(attacker->place->column!=0 && attacker->place->left->player_Identifier >19)
	{
		printf("%d found to the left of %d!\n",attacker->place->left->player_Identifier,attacker->player_Identifier );
	}
	if(attacker->place->column!=6 && attacker->place->right->player_Identifier >19){
		printf("%d found to the right of %d!\n", attacker->place->right->player_Identifier,attacker->player_Identifier );
	}




	/*
		What We Have At This Point: Location, Both Player Identifiers, and are able to
		access both players attributes.

		Perform attacking here, We already know the

}*/


/*void distant_Attack(int attacking, int attacked)
{
	//Do a recursion function for near & distant Attacks.
	//Then get the player to choose whome to attack.
}


void magic_Attack(int attacking, int attacked){
	//for this search throughtout the players and find the living ones, then ask the player to
	//choose whome to attack.
}*/



