/*
 * main.c
 *
 *  Created on: Apr 10, 2017
 *      Author: Eoin Leonard & Mohamed Jama
 */
#include <stdio.h>
#include "controlFile.h"

int main(void)
{
	setbuf(stdout,NULL);

	printf("The Main.c");
	struct slot *upLeft;
	struct slot *upRight;
	struct slot *downRight;
	struct slot *downLeft;

	int board_Size = 7;

	//here the slots are created along with the slot type, i.e. Hill, City Ground.
	createBoards(board_Size ,&upLeft, &upRight, &downLeft, &downRight);

	//Make player_Make_function

	/*
	 * runWhile(players_with_Health>1){
	 * 		call functions....
	 * }
	 *
	 *	printf("Player %s %s Is the Last Standing", player[i][i].firstName, player[i][i].lastName);
	 *
	 */

	return 0;
}


