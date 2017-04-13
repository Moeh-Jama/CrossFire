#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controlFile.h"
void player_type_function(int *t, int *d, int *l, int *m_s, int *st, int *sm, int *index);
void createCharacters(){
	srand(time(NULL));


	printf("Enter the number of players.\nNumber of Players: ");
	scanf("%d", &player_number);//number of players in the game.
	player_number=6;
	while(player_number<=1 || player_number>=7)
	{
		printf("\nThe number of players is either too high or low, remember between 2-6 players!\n");
		printf("Enter the number of players in this game!\nNumber of Players: ");
		scanf("%d", &player_number);
	}
	//printf("NamesL %s, %s", a[0], a[1]);
	for(int i=0; i<player_number; i++)
		{
		//initialise temporary player details.
			int t=0, d=0, sm=0, st=0, l=0, m_s=0;
			printf("\nPLEASE ENTER DETAILS FOR PLAYER %d", i+1);
			printf("\nEnter players First & Second name: ");
			scanf("%s%s", cases[i].name_one, cases[i].name_two);

			//strcpy(cases[i].name_one,character[i]);
			//strcpy(cases[i].name_two, character[i+1]);
			printf("\nChoose player type\n");
			printf("1.Ogre\n2.Human\n3.Wizard\n4.Elf\n");
			int choice;
			scanf("%d", &choice);
			//Player type choices created using enum.
			switch(choice)
			{
			case 1:{
				cases[i].type = Ogre;
				break;
			}
			case 2:{
				cases[i].type = Human;
				break;
			}
			case 3:{
				cases[i].type = Wizard;
				break;
			}
			case 4:{

				cases[i].type = Elf;
				break;

			}
			default:{
				printf("ERROR!");
				exit(0);
			}
			}
			//Player specifications are now sent to player_type_function to be created.
			//Then assigned to players after returned.
			player_type_function(&t, &d, &l, &m_s, &st, &sm, &i);
			cases[i].dexterity =d;
			cases[i].luck = l;
			cases[i].magic_skills =m_s;
			cases[i].strength = st;
			cases[i].smartness= sm;
			cases[i].health = 100;
			cases[i].player_Identifier=i+20;
		}
}

void player_type_function(int *t, int *d, int *l, int *m_s, int *st, int *sm, int *index){

	if(cases[*index].type == 0)
	{
		//Limitations and requirements of the Ogre Type skills are adhered in this block.

		do{
			//here both smartness and luck are assigned values
			*sm = rand()%20;
			*l = rand()%100;
			//these values are then tested to whether they adhere to the limitations, if not it loops back and re-assigns both them a values.
		}while((*sm+*l)>51);
		*m_s=0;
		do{//Strength is assigned a value, if that value adheres to the limitations
			*st = rand()%100;
		}while(*st<80);
		do{
			*d = rand()%100;
		}while(*d<80);
	}
	else if(cases[*index].type == 1)
	{
		//Limitations and requirements of the Human Type skills are adhered in this block.
		do{
			*m_s=1+rand()%100;
			*sm = 1+rand()%70;
			*st = 1+rand()%100;
			*l= 1+rand()%100;
			*d= 1+rand()%100;
		}while((*m_s+*sm+*st+*l+*d)>300);
	}
	else if(cases[*index].type == 2)
	{
		//Limitations and requirements of the Wizard Type skills are adhered in this block.
		*m_s=25;
		do{
			*sm = rand()%100;
		}while(*sm<90);
		*st = rand()%20;
		*d=rand()%100;
		do{
			*l = rand()%100;
		}while(*l<50);
	}
	else if(cases[*index].type == 3)
	{
		//Limitations and requirements of the Elf Type skills are adhered in this block.
		do{
			*m_s=rand()%80;
		}while(*m_s<50);
		do{
			*sm = rand()%100;
		}while(*sm<70);
		*st = rand()%50;
		*d=rand()%100;
		do{
			*l = rand()%100;
		}while(*l<50);
	}

	else{
		printf("ERROR CANNOT ASSIGN VALUE TO CHARACTER");
		exit(0);
	}

}
void player_type(int type)
{
	//This function is used to print out the player type, as we cannot print out enum, String.
	if(type == Ogre)
	{
		printf( "Ogre");
	}
	else if(type ==Human)
	{
		printf("Human");
	}
	else if(type ==Wizard)
	{
		printf("Wizard");
	}
	else if(type ==Elf)
	{
		printf("Elf");
	}
	else{
		printf("ERROR");
	}
}
void print_players(){
//Only prints details and general_Build characteristics of the player.
	printf("Details of Players and their specifications\n");
	for(int i=0; i<player_number; i++)
	{
		//count is used for the player_type(int) function, that we use to print the player type.
		int count = cases[i].type;
		printf("Player Name: %s %s\n", cases[i].name_one, cases[i].name_two);
		printf("Player Type: ");
		player_type(count);
		printf("\nPlayer Health: %d\n", cases[i].health);
		printf("Player Dexterity: %d\n", cases[i].dexterity);
		printf("Player Luck: %d\n", cases[i].luck);
		printf("Player Magic Skills: %d\n", cases[i].magic_skills);
		printf("Player Strength: %d\n", cases[i].strength);
		printf("Player Smartness: %d\n", cases[i].smartness);
		printf("*********************************************************\n");
	}

}
