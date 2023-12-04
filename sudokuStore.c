#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sudokuStore.h"


void sudokuChoose() {
    int sudoku1[9][9] = {
        {8, 0, 0, 2, 6, 0, 0, 0, 4},
        {0, 1, 0, 0, 8, 3, 0, 6, 2},
        {2, 6, 0, 7, 4, 0, 1, 0, 0},
        {0, 0, 6, 0, 7, 8, 2, 1, 0},
        {0, 0, 4, 0, 3, 2, 0, 8, 0},
        {0, 2, 0, 0, 0, 9, 0, 0, 7},
        {7, 4, 0, 0, 1, 6, 0, 2, 0},
        {0, 3, 0, 8, 0, 4, 0, 7, 1},
        {0, 0, 1, 0, 2, 7, 0, 0, 6}
    };

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            sudoku[i][j] = sudoku1[i][j];
        }
    }
}


    /*const char* substring = "   ";
    int count = 0;

    char* ptr = pattern;
    while ((ptr = strstr(ptr, substring)) != NULL) {
        count++;
        ptr += strlen(substring);
    }
    int i = 0;


    printf("Number of occurrences of \"%s\": %d\n", substring, count);
*/


char* returnSub(int start_index, int end_index,char * pattern) {
    char* sub_string = (char*)malloc(end_index - start_index + 1); // +1 for null terminator
    strncpy(sub_string, pattern + start_index, end_index - start_index);
    sub_string[end_index - start_index] = '\0';
    return sub_string;
}


char* sudokuString(int sudoku[9][9]) {
    const char* substring = "   ";
    const char* ptr = pattern;
    char* sudoku_string = (char*)malloc(strlen(pattern) + 1); // +1 for null terminator
    strcpy(sudoku_string, "");

    int i = 0, start_index = 0, end_index = 0, arr_x = 0, arr_y = 0;

    while ((ptr = strstr(ptr, substring)) != NULL) {
        end_index = ptr - pattern;
        indexor[arr_x][arr_y] = end_index;
        strcat(sudoku_string, returnSub(start_index, end_index,pattern));

        
        if(sudoku[arr_x][arr_y] != 0){
            
            char number_char = (char)(sudoku[arr_x][arr_y] + '0');
            strncat(sudoku_string, &number_char, 1);
        }

        else{
           strcat(sudoku_string," ") ;
        }

        ptr += strlen(substring);
        start_index = end_index + 1;
        i++;
        arr_x = i / 9;
        arr_y = i % 9;
    }

    return sudoku_string;
}
