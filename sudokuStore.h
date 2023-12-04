#ifndef SUDOKUSTORE_H
#define SUDOKUSTORE_H

char pattern[];
int indexor[9][9];
int sudoku[9][9];
void sudokuChoose();
char* returnSub(int start_index, int end_index,char * pattern);
char* sudokuString(int sudoku[9][9]);

#endif /*SUDOKUSTORE_H*/