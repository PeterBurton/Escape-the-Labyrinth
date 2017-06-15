
#include "gameMovement.h"

//------------------------------------
//	FUNCTION ask_for_movement 
//------------------------------------
char ask_for_movement() {

	bool isValid = False;
	char c;
	while (isValid == False) {
		printf("\n\tMAKE NEW MOVEMENT:\n");
printf("\tEnter a movement for the Knight:\n");
printf("\t'a' for left, 'd' for right, 'w' for up, 's' for down\n");
c = my_get_char();
if (c == 'w' || c == 'a' || c == 's' || c == 'd') {
	isValid = True;
}
else {
	printf("Invalid move, please try again!\n");
}
	}
	return c;
}

//-------------------------------------------
//	FUNCTION get_position_coord_from_pointer 
//-------------------------------------------
void get_position_coord_from_pointer(char board[6][6], char* object, int* x_pos, int* y_pos) {

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (board[i][j] == *object) {
				*x_pos = i;
				*y_pos = j;
			}
		}
	}
}

//------------------------------------
//	FUNCTION get_new_position_coord 
//------------------------------------
void get_new_position_coord(int x_pos, int y_pos, char movement, int* new_x_pos, int* new_y_pos) {

	if (movement == 'w') {
		*new_x_pos = x_pos - 1;
		*new_y_pos = y_pos;
	}
	if (movement == 'a') {
		*new_x_pos = x_pos;
		*new_y_pos = y_pos - 1;
	}
	if (movement == 's') {
		*new_x_pos = x_pos + 1;
		*new_y_pos = y_pos;
	}
	if (movement == 'd') {
		*new_x_pos = x_pos;
		*new_y_pos = y_pos + 1;
	}

}

//------------------------------------
//	FUNCTION is_winning_movement 
//------------------------------------
bool is_winning_movement(char board[6][6], char* barrel, char movement) {
	if (movement == 'd' && board[2][6] == 'B') {
	return True;
	}
	return False;
}

//------------------------------------
//	FUNCTION is_movement_safe 
//------------------------------------
bool is_movement_safe(char board[6][6], char* knight, char* barrel, char movement) {
	//Check where the knight is:
	int xPosK;
	int yPosK;
	int* xPosKPtr = &xPosK;
	int* yPosKPtr = &yPosK;
	get_position_coord_from_pointer(board, knight, xPosKPtr, yPosKPtr);
	//Check where the Barrel is:
	int xPosB;
	int yPosB;
	int* xPosBPtr = &xPosB;
	int* yPosBPtr = &yPosB;
	get_position_coord_from_pointer(board, barrel, xPosBPtr, yPosBPtr);
	//Check where the Knight would move to:
	int newXPosK;
	int newYPosK;
	int* newXPtrK = &newXPosK;
	int* newYPtrK = &newYPosK;
	get_new_position_coord(xPosK, yPosK, movement, newXPtrK, newYPtrK);
	
	//Check the possible ways moving the knight could fail:
	if (newXPosK < 0 || newYPosK < 0 ) {
		return False;
	}
	if (newXPosK > 5 || newYPosK > 5 ) {
		return False;
	}
	if (board[newXPosK][newYPosK] == 'W') {
		return False;
	}
	
	if (board[newXPosK][newYPosK] == 'B'){
		//Check where the Barrel would move to:
		int newXPosB;
		int newYPosB;
		int* newXPtrB = &newXPosB;
		int* newYPtrB = &newYPosB;
		get_new_position_coord(xPosB, yPosB, movement, newXPtrB, newYPtrB);
		//check possible ways moving the barrel could fail
		if (board[newXPosB][newYPosB] == 'W') {
			return False;
		}
		if (newXPosB < 0 || newYPosB < 0) {
			return False;
		}
		if (newXPosB == 2 && newYPosB == 6) {
			return True;
		}
		if (newXPosB > 5 || newYPosB > 5) {
			return False;
		}
	}
	
	return True;

}

//------------------------------------
//	FUNCTION perform_movement 
//------------------------------------
bool perform_movement(char board[6][6], char** knight, char** barrel, int* steps, int* treasures) {
	char move = ask_for_movement();
	bool isSafe = is_movement_safe(board, *knight, *barrel, move);
	bool winner = False;
	//Check where the knight is
	int xPosK;
	int yPosK;
	int* xPosKPtr = &xPosK;
	int* yPosKPtr = &yPosK;
	get_position_coord_from_pointer(board, *knight, xPosKPtr, yPosKPtr);
	if (isSafe) {

		(int)*steps = *steps + 1;

		if (move == 'w') {
			if (board[xPosK - 1][yPosK] == ' ') {
				board[xPosK - 1][yPosK] = 'K';
				*knight = &board[xPosK - 1][yPosK];
				board[xPosK][yPosK] = ' ';
			}
			if (board[xPosK-1][yPosK] == 'T') {
				*treasures = *treasures + 1;
				board[xPosK - 1][yPosK] = 'K';
				*knight = &board[xPosK - 1][yPosK];
				board[xPosK][yPosK] = ' ';
			}
			if (board[xPosK-1][yPosK] == 'B') {
				board[xPosK - 2][yPosK] = 'B';
				*barrel = &board[xPosK - 2][yPosK];
				board[xPosK - 1][yPosK] = 'K';
				*knight = &board[xPosK - 1][yPosK];
				board[xPosK][yPosK] = ' ';

			}
		}

		if(move == 'a') {
			if (board[xPosK][yPosK-1] == ' ') {
				board[xPosK][yPosK-1] = 'K';
				*knight = &board[xPosK][yPosK-1];
				board[xPosK][yPosK] = ' ';
			}
			if (board[xPosK][yPosK-1] == 'T') {
				*treasures = *treasures + 1;
				board[xPosK][yPosK-1] = 'K';
				*knight = &board[xPosK][yPosK-1];
				board[xPosK][yPosK] = ' ';
			}
			if (board[xPosK][yPosK-1] == 'B') {
				board[xPosK][yPosK-2] = 'B';
				*barrel = &board[xPosK][yPosK-2];
				board[xPosK ][yPosK-1] = 'K';
				*knight = &board[xPosK][yPosK-1];
				board[xPosK][yPosK] = ' ';
			}
		}

		if (move == 's') {
			if (board[xPosK + 1][yPosK] == ' ') {
				board[xPosK + 1][yPosK] = 'K';
				*knight = &board[xPosK + 1][yPosK];
				board[xPosK][yPosK] = ' ';
			}
			if (board[xPosK + 1][yPosK] == 'T') {
				*treasures = *treasures + 1;
				board[xPosK + 1][yPosK] = 'K';
				*knight = &board[xPosK + 1][yPosK];
				board[xPosK][yPosK] = ' ';
			}
			if (board[xPosK + 1][yPosK] == 'B') {
				board[xPosK + 2][yPosK] = 'B';
				*barrel = &board[xPosK + 2][yPosK];
				board[xPosK + 1][yPosK] = 'K';
				*knight = &board[xPosK + 1][yPosK];
				board[xPosK][yPosK] = ' ';

			}
		}

		if (move == 'd') {
			if (board[xPosK][yPosK + 1] == ' ') {
				board[xPosK][yPosK + 1] = 'K';
				*knight = &board[xPosK][yPosK + 1];
				board[xPosK][yPosK] = ' ';
			}
			if (board[xPosK][yPosK + 1] == 'T') {
				*treasures = *treasures + 1;
				board[xPosK][yPosK + 1] = 'K';
				*knight = &board[xPosK][yPosK + 1];
				board[xPosK][yPosK] = ' ';
			}
			if (board[xPosK][yPosK + 1] == 'B') {
				board[xPosK][yPosK + 2] = 'B';
				*barrel = &board[xPosK][yPosK + 2];
				board[xPosK][yPosK + 1] = 'K';
				*knight = &board[xPosK][yPosK + 1];
				board[xPosK][yPosK] = ' ';
			}
		}
	}
	winner = is_winning_movement(board, *barrel, move);
	return winner;
	
}


