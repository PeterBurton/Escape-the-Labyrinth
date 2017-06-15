
#include "gameSetup.h"

//------------------------------------
//	FUNCTION game_instructions 
//------------------------------------
void game_instructions() {
	printf("---------------------------------\n");
	printf(" ESCAPE FROM THE LABYRINTH\n");
	printf("---------------------------------\n");
	printf("Instructions. \n\n");
	printf("Use the keys 'a', 'd', 'w' and 'x' to move the knight ('K) left, right, up and down over the labyrinth, respectively\n");
	printf("'K' can only be moved within the board. Moreover, it can not be moved into any wall position ('W)\n");
	printf("The goal of the game is to use ('K') to push the barrel ('B') towards the escape of the labyrinth, indicated by -->\n");
	printf("On its way, ('K') can collect treasures ('T') so as to make extra points on its journey.\n");
	printf("However, any treasure is susceptible of being buried by pushing ('B') into its position.\n");
	printf("Press any key so as to start the game\n");
	char c = my_get_char();
}

//------------------------------------
//	FUNCTION set_game_initial_status 
//------------------------------------
void set_game_initial_status(char board[6][6], char** knight, char** barrel, int* steps, int* treasures) {

	board[0][0] = ' ';
	board[0][1] = ' ';
	board[0][2] = ' ';
	board[0][3] = ' ';
	board[0][4] = ' ';
	board[0][5] = 'T';

	board[1][0] = ' ';
	board[1][1] = ' ';
	board[1][2] = 'W';
	board[1][3] = ' ';
	board[1][4] = 'W';
	board[1][5] = 'W';

	board[2][0] = 'T';
	board[2][1] = 'W';
	board[2][2] = 'W';
	board[2][3] = ' ';
	board[2][4] = ' ';
	board[2][5] = ' ';

	board[3][0] = ' ';
	board[3][1] = ' ';
	board[3][2] = ' ';
	board[3][3] = ' ';
	board[3][4] = ' ';
	board[3][5] = 'W';

	board[4][0] = 'W';
	board[4][1] = 'B';
	board[4][2] = 'W';
	board[4][3] = 'W';
	board[4][4] = ' ';
	board[4][5] = 'W';

	board[5][0] = 'K';
	board[5][1] = ' ';
	board[5][2] = ' ';
	board[5][3] = 'T';
	board[5][4] = ' ';
	board[5][5] = ' ';
	

	*steps = 0;
	*treasures = 0;
	*knight = &board[5][0];
	*barrel = &board[4][1];


}

//------------------------------------
//	FUNCTION display_board 
//------------------------------------
void display_board(char board[6][6]) {
	printf("\t\t\tBoard Status\n");
	printf("\t------------------------------------------------\n");
	printf("\t|%c\t|%c\t|%c\t|%c\t|%c\t|%c\t|\n", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5]);
	printf("\t------------------------------------------------\n");
	printf("\t|%c\t|%c\t|%c\t|%c\t|%c\t|%c\t|\n", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5]);
	printf("\t------------------------------------------------\n");
	printf("\t|%c\t|%c\t|%c\t|%c\t|%c\t|%c\t|-->\n", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5]);
	printf("\t------------------------------------------------\n");
	printf("\t|%c\t|%c\t|%c\t|%c\t|%c\t|%c\t|\n", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5]);
	printf("\t------------------------------------------------\n");
	printf("\t|%c\t|%c\t|%c\t|%c\t|%c\t|%c\t|\n", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5]);
	printf("\t------------------------------------------------\n");
	printf("-->\t|%c\t|%c\t|%c\t|%c\t|%c\t|%c\t|\n", board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5]);
	printf("\t------------------------------------------------\n");



}

//------------------------------------
//	FUNCTION display_game_status 
//------------------------------------
void display_game_status(char board[6][6], int steps, int treasures) {
	
	display_board(board);
	printf("-------------------------------------------------------\n");
	printf("\t\tGame Status\n");
	printf("-------------------------------------------------------\n");
	printf("\tSteps Done = %d", steps);
	printf("\tTreasures Collected = %d", treasures);

	
}

//------------------------------------
//	FUNCTION play_game 
//------------------------------------
void play_game() {

	char board[6][6] ;
	char* knight = NULL;
	char* barrel = NULL;
	char** knightPtr = &knight;
	char** barrelPtr = &barrel;
	int steps =0;
	int treasures =0;
	int* stepsPtr = &steps;
	int* treasuresPtr = &treasures;
	game_instructions();

	set_game_initial_status(board,  knightPtr,  barrelPtr,  stepsPtr,  treasuresPtr);
	display_game_status(board, steps, treasures);
	bool isFinished = False;

	while (isFinished==False) {
		
		isFinished = perform_movement(board, knightPtr, barrelPtr, stepsPtr, treasuresPtr);
		display_game_status(board, steps, treasures);
	}

	printf("\n-------------------------------------------------------\n");
	printf("\tGAME FINISHED:\n");
	printf("\tEscaped from the labyrinth after %d moves,\n\t with %d treasures collected\n", steps, treasures);
}
