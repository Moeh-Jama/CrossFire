#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controlFile.h" 
#ifndef CONTROLFILE_H_
#define CONTROLFILE_H_
#endif /* CONTROLFILE_C_ */
#define BOARD_SIZE 7
#define REQ_DISTANCE 4
#include <time.h>
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

void createBoards(int board_Size, struct slot **upLeft, struct slot **upRight, struct slot **downRight, struct slot **downLeft){
	//Here we create the boards.
	board = malloc(board_Size * sizeof(struct slot*));

	srand(time(NULL));
	for(int i=0; i<board_Size; i++)
	{
		board[i] = malloc(board_Size * sizeof(struct slot));
		for(int k=0; k<board_Size; k++)
		{
			board[i][k].player_Identifier = -1;
			board[i][k].row = i;
			board[i][k].column =k;
			int randomPlace = 5;
			do{
				randomPlace = rand()%3;
			}while(randomPlace>2 || randomPlace<0);
			board[i][k].slotType = randomPlace;
			//printf("(%d, %d)\n",board[i][k].row, board[i][k].column);
		}
	}

	//Pointing the edges of the board to their neighbors
	for(int i=1; i<board_Size-1; i++)
	{

		//Top Edge
		board[0][i].right = &board[0][i+1];
		board[0][i].left = &board[0][i-1];
		board[0][i].down = &board[i][0];
		board[0][i].up = NULL;
		//Bottom Edge
		board[board_Size-1][i].right = &board[board_Size-1][i+1];
		board[board_Size-1][i].left = &board[board_Size-1][i-1];
		board[board_Size-1][i].up = &board[board_Size-2][i];

		//Right Edge
		board[i][0].right = &board[i][1];
		board[i][0].left = NULL;
		board[i][0].up = &board[i+1][0];
		board[i][0].down = &board[i-1][0];

		//Left Edge
		board[i][board_Size-1].right = NULL;
		board[i][board_Size-1].left = &board[board_Size-1][board_Size-2];
		board[i][board_Size-1].up = &board[i-1][board_Size-1];
		board[i][board_Size-1].down = &board[i+1][board_Size-1];

		//Inner Board Slots
		for(int k=1; k<board_Size-1; k++)
		{
			board[i][k].right = &board[i][k+1];
			board[i][k].left = &board[i][k-1];
			board[i][k].up = &board[i-1][k];
			board[i][k].down = &board[i+1][k];
		}

	}
	//Top Left.
	board[0][0].right = &board[0][1];
	board[0][0].down = &board[1][0];
	board[0][0].up =NULL;
	board[0][0].left = NULL;
	//Top Right.
	board[0][board_Size-1].left = &board[0][board_Size-2];
	board[0][board_Size-1].down = &board[1][board_Size-1];
	board[0][board_Size-1].right=NULL;
	board[0][board_Size-1].up = NULL;
	//Down Right.
	board[board_Size-1][board_Size-1].up = &board[board_Size-2][board_Size-1];
	board[board_Size-1][board_Size-1].left = &board[board_Size-1][board_Size-2];
	board[board_Size-1][board_Size-1].down = NULL;
	board[board_Size-1][board_Size-1].right=NULL;
	//Down Left.
	board[board_Size-1][0].right = &board[board_Size-1][1];
	board[board_Size-1][0].up = &board[board_Size-2][0];
	board[board_Size-1][0].down = NULL;
	board[board_Size-1][0].left = NULL;

	//All Four Corner of the board are taken by the struct slots **Values.
	*upLeft = &board[0][0];
	*upRight = &board[0][board_Size-1];
	*downRight = &board[board_Size-1][board_Size-1];
	*downLeft = &board[board_Size-1][0];
}

for(int i=0; i<player_number; i++)
	{
		printf("Current Player: (%d,%d)\n",cases[i].place->row,cases[i].place->column);

		printf("Choose a move option:\n");
		printf("1.Up\n2.Down\n3.Right\n4.Left\n");
		int choice;
		scanf("%d", &choice);

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