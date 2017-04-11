/*
 * controlFile.c
 *
 *  Created on: Apr 10, 2017
 *      Author: ja123
 */

#ifndef CONTROLFILE_H_
#define CONTROLFILE_H_



#endif /* CONTROLFILE_C_ */
enum slot_level {Hill, City, Ground};
struct slot{
	int row ,column;
	struct slot *up;
	struct slot *right;
	struct slot *down;
	struct slot *left;

	int number_Of_Players;
	int player_Identifier;
	enum slot_level slotType;
	/*
	 *
	 * Add Levels
	 */
};
struct slot **board;
struct players{
	int player_Identifier;
	struct slot *place;
};
struct players cases[5];

void createBoards(int board_Size, struct slot **upLeft, struct slot **upRight, struct slot **downRight, struct slot **downLeft);
void near_Attack(struct players * attacker);
int check_More_Than_One(int player_identifier);
void near_Attack(struct players * attacker);
int distantAttack(struct slot * victim);
//int check_adjecent_Slots(int player_identifer);
