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

	int player_Identifier;
	enum slot_level slotType;
	/*
	 *
	 * Add Levels
	 */
};
struct slot **board;
