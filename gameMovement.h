
//------------------------------------
//	To avoid multiple inclusions 
//------------------------------------
#ifndef _GAMEMOVEMENTH_
#define _GAMEMOVEMENTH_

//------------------------------------
//	Include Libraries 
//------------------------------------
#include <stdio.h>
#include "auxiliary.h"

//------------------------------------
//	FUNCTION ask_for_movement 
//------------------------------------
char ask_for_movement();

//-------------------------------------------
//	FUNCTION get_position_coord_from_pointer 
//-------------------------------------------
void get_position_coord_from_pointer(char board[6][6], char* object, int* x_pos, int* y_pos);

//------------------------------------
//	FUNCTION get_new_position_coord 
//------------------------------------
void get_new_position_coord(int x_pos, int y_pos, char movement, int* new_x_pos, int* new_y_pos);

//------------------------------------
//	FUNCTION is_winning_movement 
//------------------------------------
bool is_winning_movement(char board[6][6], char* barrel, char movement);

//------------------------------------
//	FUNCTION is_movement_safe 
//------------------------------------
bool is_movement_safe(char board[6][6], char* knight, char* barrel, char movement);

//------------------------------------
//	FUNCTION perform_movement 
//------------------------------------
bool perform_movement(char board[6][6], char** knight, char** barrel, int* steps, int* treasures);

//------------------------------------
//	End of file 
//------------------------------------
#endif
