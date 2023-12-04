#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

void removeChar(char *str, char target);
char *newString(int cursor, char *str);
double sudokuFill(int sudoku[9][9]);


#endif /*SUDOKUSOLVER_H*/