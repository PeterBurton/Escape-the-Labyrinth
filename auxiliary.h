
//------------------------------------
//	To avoid multiple inclusions 
//------------------------------------
#ifndef _AUXILIARYH_
#define _AUXILIARYH_

//------------------------------------
//	Include Libraries 
//------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//------------------------------------
//	TYPEDEF 
//------------------------------------
enum Boolean { False, True };
typedef enum Boolean bool;

//--------------------------------------------------
// gen_num
//--------------------------------------------------
/* 
Generates a random number in the interval [lb, ub)
Note: Do not forget to include the following instruction at the beginning of your main() method:
srand(time(NULL));
*/
int gen_num(int lb, int ub);

//--------------------------------------------------
// my_getchar
//--------------------------------------------------
char my_get_char();

//------------------------------------
//	End of file 
//------------------------------------
#endif
