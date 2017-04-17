/*
 * 		searchAttack.c
 *
 *  	Created on: Apr 10, 2017
 *      Author: Eoin Leonard & Mohamed Jama.
 */

#include <stdio.h>
#include "controlFile.h"
int getDistance(struct slot*attacker, struct slot*attacked)
{
	//This Function calculates the distance between two players.
	int result ,column_result, row_result;
	//These if and else if statements are used in order to keep the numbers positive.
	if(attacker->row >= attacked->row)
	{
		row_result = (attacker->row) - (attacked->row);
	}
	else if(attacked->row >= attacker->row)
	{
		row_result = (attacked->row) - (attacker->row);
	}

	if(attacker->column >= attacked->column)
		{
		column_result = (attacker->column) - (attacked->column);
		}
	else if(attacked->column >= attacker->column)
		{
			column_result = (attacked->column) - (attacker->column);
		}

	//Result should always be positive to derive the correct distance.
	result = row_result+column_result;
	return result;
}


void search(struct players *currentPlayer)
{
	int attackable_Players[5][5];
	int attack_Index[5];
	for(int i=0;i<5;i++)
	{
		attackable_Players[i][0] = -2;
		attackable_Players[i][1] = -2;
		attack_Index[i]=9;
	}
	int k=0;
	//A method of getting the distance between two characters.
	int result;

	for(int j=0;j<player_number;j++)
	{
		//Since we get the distance between two characters we can now filter the users beyond our scope. less than 2 and greater than 4.
		if(currentPlayer->player_Identifier != cases[j].player_Identifier && cases[j].health>0)
		{
			//The distance between two players is achieved with the getDistance function.
			result = getDistance(currentPlayer->place, cases[j].place);
			if(result<=4 && result>1){
				//Only distances of 4-2 slots will be used
				attackable_Players[k][0] =cases[j].place->row;
				attackable_Players[k][1]=cases[j].place->column;
				attack_Index[k]=j;
				k++;
			}
		}
	}
	printf("Total Found\n");
	if(k!=0)
	{
		printf("Choose a player to Attack!\n");
		for(int i=0;i<k;i++)
		{
			printf("(%d) [%d, %d]\t",i+1,attackable_Players[i][0],attackable_Players[i][1]);
			printf("PLayer Name :%s %s\n", cases[attack_Index[i]].name_one,cases[attack_Index[i]].name_two);
		}
		int choice;
		scanf("%d", &choice);
		while(choice<1 || choice>k)
		{
			printf("Invalid choice select again!\nEnter Choice: ");
			scanf("%d", &choice);
		}
		Attack(2, currentPlayer, &cases[attack_Index[choice-1]]);
	}else{
		printf("I'm sorry There's not players within distance to perform distant attack\n");
	}
}
void near_Attack(struct players * currentPlayer)
{
	//for this search throughout the players and find the living ones, then ask the player to
	//choose whom to attack.
	int attackable_Players[5][5];
	int attack_Index[5];
	for(int i=0;i<5;i++)
	{
		attackable_Players[i][0] = -2;
		attackable_Players[i][1] = -2;
		attack_Index[i]=9;
	}
	int k=0;
		//A method of getting the distance between two characters.
	int result;
	for(int j=0;j<player_number;j++)
	{
		result = getDistance(currentPlayer->place, cases[j].place);
		//Since we get the distance between two characters we can now filter the users beyond our scope. less than 2 and greater than 4.
		if(result <2 && (currentPlayer->player_Identifier != (j+20)) && cases[j].health>0)
		{
			attackable_Players[k][0] =cases[j].place->row;
			attackable_Players[k][1]=cases[j].place->column;
			attack_Index[k]=j;
			k++;
		}
	}

	printf("Total Found\n");
	if(k!=0)
	{
		printf("Choose a player to Attack!\n");
		for(int i=0;i<k;i++)
		{
			printf("(%d) [%d, %d]\t",i+1,attackable_Players[i][0],attackable_Players[i][1]);
			printf("PLayer Name :%s %s\n", cases[attack_Index[i]].name_one,cases[attack_Index[i]].name_two);
		}
		int choice;
		scanf("%d", &choice);
		while(choice<1 || choice>k)
		{
			printf("Invalid choice select again!\nEnter Choice: ");
			scanf("%d", &choice);
		}
		Attack(1, currentPlayer, &cases[attack_Index[choice-1]]);
	}else{
		printf("I'm sorry There's not players within distance to perform near attack\n");
	}
}

void magic_Attack(struct players * currentPlayer){
	//for this search throughtout the players and find the living ones, then ask the player to
	//choose whome to attack.
	int attackable_Players[5][5];
		int attack_Index[5];
		for(int i=0;i<5;i++)
		{
			attackable_Players[i][0] = -2;
			attackable_Players[i][1] = -2;
			attack_Index[i]=9;
		}
		int k=0;
		//A method of getting the distance between two characters.
		for(int j=0;j<player_number;j++)
		{
			//Since we get the distance between two characters we can now filter the users beyond our scope. less than 2 and greater than 4.
			if(currentPlayer->player_Identifier != cases[j].player_Identifier && cases[j].health>0)
			{
				attackable_Players[k][0] =cases[j].place->row;
				attackable_Players[k][1]=cases[j].place->column;
				attack_Index[k]=j;
				k++;
			}
		}
		printf("Total Found\n");
		if(k!=0)
		{
			printf("Choose a player to Attack!\n");
			for(int i=0;i<k;i++)
			{
				printf("(%d) [%d, %d]\t",i+1,attackable_Players[i][0],attackable_Players[i][1]);
				printf("PLayer Name :%s %s\n", cases[attack_Index[i]].name_one,cases[attack_Index[i]].name_two);
			}
			int choice;
			scanf("%d", &choice);
			while(choice<1 || choice>k)
			{
				printf("Invalid choice select again!\nEnter Choice: ");
				scanf("%d", &choice);
			}
			Attack(3, currentPlayer, &cases[attack_Index[choice-1]]);
		}
		else{
			printf("I'm sorry There's not players within distance to perform Magic attack\n");
		}
}



