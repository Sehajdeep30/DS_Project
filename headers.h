#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include "sudokuStore.h"
#include "profile.h"
#include "sudokuSolver.h"

// Function declarations
void removeChar(char *str, char target);
char *newString(int cursor, char *str);
void sudokuFill(int sudoku[9][9]);


