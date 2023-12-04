#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

void sudokuChoose();
char* returnSub(int start_index, int end_index,char * pattern);
char* sudokuString(int sudoku[9][9]);

void removeChar(char *str, char target);
char *newString(int cursor, char *str);
double sudokuFill(int sudoku[9][9]);

#endif /*SUDOKUSOLVER_H*/
