
//------------------------------------
//	To avoid multiple inclusions 
//------------------------------------
#ifndef _GAMESETUPH_
#define _GAMESETUPH_

//------------------------------------
//	Include Libraries 
//------------------------------------
#include <stdio.h>
#include "auxiliary.h"
#include "gameMovement.h"

//------------------------------------
//	FUNCTION game_instructions 
//------------------------------------
void game_instructions();

//------------------------------------
//	FUNCTION set_game_initial_status 
//------------------------------------
void set_game_initial_status(char board[6][6], char** knight, char** barrel, int* steps, int* treasures);

//------------------------------------
//	FUNCTION display_board 
//------------------------------------
void display_board(char board[6][6]);

//------------------------------------
//	FUNCTION display_game_status 
//------------------------------------
void display_game_status(char board[6][6], int steps, int treasures);

//------------------------------------
//	FUNCTION play_game 
//------------------------------------
void play_game();

//------------------------------------
//	End of file 
//------------------------------------
#endif
