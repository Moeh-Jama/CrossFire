/*
 * controlFile.c
 *
 *  Created on: Apr 10, 2017
 *      Author: ja123
 */

#ifndef CONTROLFILE_H_
#define CONTROLFILE_H_



#endif /* CONTROLFILE_C_ */
#define BOARD_SIZE 7
#define REQ_DISTANCE 4


typedef int bool;
enum { false, true };


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
};
struct slot **board;
struct slot **temp;
enum player_Type {Ogre, Human, Wizard, Elf};
struct players{
	char name_one[20];
	char name_two[20];
	int health;
	int player_Identifier;
	enum player_Type type;
	int dexterity, luck, magic_skills, strength, smartness;

	struct slot *place;
};
struct players cases[6];
int player_number;
int players_With_Health;
void better_Near_Attack(struct players * currentPlayer);
void search(struct players *currentPlayer);
void print_players();
void terraine_type(int type);
void player_type(int type);
void magic_Attack(struct players * currentPlayers);
void attack_Menu(struct players * currentPlayers);
void moded_Capabilities(struct players * currentPlayer);
void Attack(int type_attack, struct players * attacker, struct players * attacked);
void createCharacters();
int getDistance(struct slot*attacker, struct slot*attacked);
void createBoards(int board_Size, struct slot **upLeft, struct slot **upRight, struct slot **downRight, struct slot **downLeft);
void near_Attack(struct players * attacker);
