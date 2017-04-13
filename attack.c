#include <stdio.h>
#include <stdlib.h>
#include "controlFile.h">
//Change this to int type, adn this function will actually be used for the attacks.
void Attack(int ID_Player)
{
    // get the sum of the differences of the axis
    int a, b;
    int c, d;
    int differ;
    int i;
    int Defender;
    int type_attack;
    int arr_close[6];
    int arr_ranged[6];
   
    int arr_magic[6];bool attack_close = false;
    bool distant_attack = false;
    bool magic= false;
   
    for (i=0;i<=6;i++)
    {
        arr_close[6]=0;
        arr_ranged[6]=0;
        arr_magic[6]=0;
    }
 
    a=players[ID_Player].row;
    c=players[ID_Player].column;
 
    for (i=0;i<=Remaining_Players;i++)
    {
        attack_close = false;
        distant_attack = false;
        magic= false;
        if(i!=ID_Player)
        {
        differ=0;
        c=players[ID_Player].row;
        d=players[ID_Player].column;
 
        differ=differ+abs(a-c);
        differ=differ+abs(b-d);
 
        if (differ==1 || differ==0) //close attack
        {
            attack_close=true;
        }
        if (differ<5)
        {
            ranged_attack=true;
        }
        if (150<(players[ID_Player].Smartness+players[ID_Player].Magic_Skills))
        {
            magic=true;
        }
 
        if (attack_close==true || ranged_attack==true || magic==true)
        {
            printf("%d) To attack player %d at (%d,%d)", (i+1), (i+1), a, b);
            if (attack_close==true)
            {
                arr_close[i]=1;}
            if (ranged_attack==true)
            {
                arr_ranged[i]=1;}
            if (magic==true)
            {
                arr_magic[i]=1;}
        }
        }
    }
    scanf("%d", &Defender);
    if (arr_close[i]==1)
    {
        printf("1)close attack");}
    if (arr_ranged[i]==1)
    {
        printf("2)ranged attack");}
    if (arr_magic[i]==1)
    {
        printf("3)magic attack");}
    scanf("%d", &type_attack);
 
    if (type_attack==1)// Attack for Melee
   
    {
        if (players[Defender].Strength<=70)
        {
            players[Defender].Health =
            players[Defender].Health - (0.5* players[ID_Player].Strength);
        }
        if (players[Defender].Strength>70)
        {
            players[ID_Player].Health =
            players[ID_Player].Health - (0.3* players[Defender].Strength);
        }
    }
    if (type_attack==2)//Attack for Ranged
    {
        if (players[ID_Player].Dexterity>players[Defender].Dexterity)
        {
            players[Defender].Health = players[Defender].Health - (0.3* players[ID_Player].Strength);}
    }
    if (type_attack==3)//Attack for magic
    {
        players[Defender].Health =
        players[Defender].Health - (0.5* players[ID_Player].Magic_Skills + 0.2*players[ID_Player].Smartness);
       
    }
