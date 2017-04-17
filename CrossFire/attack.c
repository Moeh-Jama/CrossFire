#include <stdio.h>
#include <stdlib.h>
#include "controlFile.h"
/*
 * Author: Eoin Leonard & Mohamed Jama
 * Date: 11-04-17
 */
void attack_Menu(struct players * currentPlayer)
{
	//Here The Player is asked to choose an attack type to perform.
	printf("Attacker IS: %s", currentPlayer->name_one);
	printf("\n\nPlease Choose an Attack Method\n1.Near Attack\n2.Distant Attack\n3.Magic Attack\nEnter Choice: ");
	int attackChoice;
	scanf("%d", &attackChoice);
	int one=0;
	while(attackChoice<1 || attackChoice>3)
	{
		printf("Invalid choice, outside of range of 1-3\nPlease Choose again an Attack Method\n1.Near Attack\n2.Distant (Ranged) Attack\n3.Magic Attack\nEnter Choice: ");
		scanf("%d", &attackChoice);
	}
	if(attackChoice ==3 && ((currentPlayer->magic_skills+currentPlayer->smartness) <=150))
	{	//We warn the player that they may waste an attack if they perform the magic attack without the necessary capabilities.
		printf("Are you sure you want to use a magic attack,\n your capabilities aren't high enough to perform this attack");
		printf("\n1.No\nPress 2 or any number then for Yes\nEnter Choice: ");
		int newChoice;
		scanf("%d", &newChoice);
		if(newChoice==1)
		{
			printf("\n\nPlease Choose an Attack Method\n1.Near Attack\n2.Distant (Ranged) Attack\n3.Magic Attack\nEnter Choice: ");
			scanf("%d", &attackChoice);
		}
		while(attackChoice<1 || attackChoice>3)
		{
			printf("Invalid choice, outside of range of 1-3\nPlease Choose again an Attack Method\n1.Near Attack\n2.Distant (Ranged) Attack\n3.Magic Attack\nEnter Choice: ");
			scanf("%d", &attackChoice);
		}
	}
	if(attackChoice==1)
	{

		while(attackChoice==1 && one==1)
		{
			printf("Invalid, there are no players around you\nPlease CHoose Again!\n");
			printf("\nPlease Choose an Attack Method\n1.Near Attack\n2.Distant (Ranged) Attack\n3.Magic Attack\nEnter Choice: ");
			scanf("%d", &attackChoice);
			while(attackChoice<1 || attackChoice>3)
			{
				printf("Invalid choice, outside of range of 1-3\nPlease Choose again an Attack Method\n1.Near Attack\n2.Distant (Ranged) Attack\n3.Magic Attack\nEnter Choice: ");
				scanf("%d", &attackChoice);
			}
		}
	}
	switch(attackChoice)
	{
	case 1:{
		printf("\nNear Attack");
		near_Attack(currentPlayer);
		break;
	}
	case 2:{
		printf("\nDistant Attack\n");
		search(currentPlayer);
		break;
	}
	case 3:{
		printf("\nMagic Attack\n");
		magic_Attack(currentPlayer);
		break;
	}
	default:{
		printf("Error Incorrect entry!");
		exit(0);
	}
	}
}
//Change this to integer type, and this function will actually be used for the attacks.
void Attack(int type_attack, struct players * attacker, struct players * attacked)
{
    if (type_attack==1)// Near Attack operations
    {//if attacked players strength is less than or equal to 70 they are hit.
        if (attacked->strength<=70)
        {
            attacked->health-=(0.5* attacker->strength);
            if(attacked->health<=0)
            {
            	printf("\nCritical Hit against %s %s\n", attacked->name_one, attacked->name_two);
            	players_With_Health--;
            }
        }//if attacked players strength is greater than 70 then attacker is hit.
        else if (attacked->strength>70)
        {
           attacker->health-=(0.3* attacked->strength);
           if(attacker->health<=0)
           {
        	   printf("\nCritical Self-inflicted Hit by %s %s\n", attacker->name_one, attacker->name_two);
        	   players_With_Health--;
           }
        }
    }
    else if (type_attack==2)//Distant Attack operations
    {//If attackers dexterity is greater than the player to be attacked dexterity is greater  we may perform action.
        if (attacker->dexterity>attacked->dexterity)
        {
           attacked->health-= (0.3* attacker->strength);
           if(attacked->health<=0)
           {
        	   printf("\nCritical Hit against %s %s\n", attacked->name_one, attacked->name_two);
        	   attacked->health=0;
        	   players_With_Health--;
           }
        }
    }
    else if (type_attack==3)//Magic Attack operation
    {//if attackers intelligence+their magic is greater than 150 they may perform magic Attack.
    	if(attacker->smartness+attacker->magic_skills >150)
    	{//Attack points.
    		attacked->health -= (0.5* attacker->magic_skills + 0.2*attacker->smartness);
            if(attacked->health<=0)
            {
            	printf("\nCritical Hit against %s %s\n", attacked->name_one, attacked->name_two);
            	attacked->health=0;
            	players_With_Health--;
            }
    	}
    	else{
    		printf("\nYour Player Is too Weak to Perform This Attack.\n");
    	}
    }
    else{
        printf("Player attack was not chosen.\n");
    }
}
