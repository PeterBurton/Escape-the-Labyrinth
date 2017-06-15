
#include "auxiliary.h"

//--------------------------------------------------
// gen_num
//--------------------------------------------------
int gen_num(int lb, int ub) {
	int num = (rand() % (ub - lb)) + lb;

	return num;
}
/* Note: Do not forget to include the following instruction at the beginning of your main() method:
srand(time(NULL));
*/

//--------------------------------------------------
// my_getchar
//--------------------------------------------------
char my_get_char() {
	//1. We create the variable for hosting the char
	char my_char = ' ';

	//2. We create an extra variable to consume any other characters entered until a return is pressed
	bool line_consumed = False;
	char dummy_char = ' ';

	//3. We consume the first char entered, i.e., the one we are interested at
	my_char = getchar();

	//4. While still there are remaining characters
	while (line_consumed == False) {
		//4.1. We consume the next character
		dummy_char = getchar();

		//4.2. If the new character is the end of line one, we can ensure we have consumed the entire line.
		if (dummy_char == '\n')
			line_consumed = True;
	}

	//5. We return the first character entered by the user, i.e., the one we are interested at
	return my_char;
}




