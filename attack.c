#include <stdio.h>
#include <stdlib.h>
#include "controlFile.h"
/*
 * Author: Eoin Leonard & Mohamed Jama
 * Date: 11-04-17
 */
//Change this to int type, adn this function will actually be used for the attacks.
void Attack(int type_attack, struct players * attacker, struct players * attacked)
{

    //Assume player attack has already been chosen
    if (type_attack==1)// Attack for Melee
   
    {
        if (attacked->strength<=70)
        {
            attacked->health-=(0.5* attacker->strength);
            //players[Defender].Health - (0.5* players[ID_Player].Strength);
        }
        else if (attacked->strength>70)
        {
           attacker->health-=(0.3* attacked->strength);
           // players[ID_Player].Health - (0.3* players[Defender].Strength);
        }
    }
    else if (type_attack==2)//Attack for Ranged
    {
        if (attacker->dexterity>attacked->dexterity)
        {
           attacked->health-= (0.3* attacker->strength);
           // players[Defender].Health - (0.3* players[ID_Player].Strength);
        }
    }
    else if (type_attack==3)//Attack for magic
    {
       attacked->health -= (0.5* attacker->magic_skills + 0.2*attacker->smartness);
       // players[Defender].Health - (0.5* players[ID_Player].Magic_Skills + 0.2*players[ID_Player].Smartness);
       
    }
    else{
        printf("Player attack was not chosen.\n");
    }
}
