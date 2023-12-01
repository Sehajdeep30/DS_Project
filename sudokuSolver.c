#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sudokuStore.h"

// Function declaration
char* returnSub(int start_index, int end_index,char * pattern);

char* sudokuString(int sudoku[9][9]) {
    const char* substring = "   ";
    const char* ptr = pattern;
    char* sudoku_string = (char*)malloc(strlen(pattern) + 1); // +1 for null terminator
    strcpy(sudoku_string, "");

    int i = 0, start_index = 0, end_index = 0, arr_x = 0, arr_y = 0;

    while ((ptr = strstr(ptr, substring)) != NULL) {
        end_index = ptr - pattern;
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

char* returnSub(int start_index, int end_index,char * pattern) {
    char* sub_string = (char*)malloc(end_index - start_index + 1); // +1 for null terminator
    strncpy(sub_string, pattern + start_index, end_index - start_index);
    sub_string[end_index - start_index] = '\0';
    return sub_string;
}

/*
void display(int str_index, int block_index) {
    int arr_x = block_index / 9, arr_y = block_index % 9, number = sudoku1[arr_x][arr_y];

    for (int i = 0; i < strlen(pattern); i++) {
        if (i == str_index && number != 0) {
            printf("%d", number);
            continue;
        }
        printf("%c", pattern[i]);
    }
}
*/
int main() {
    char* result = sudokuString(sudoku1);
    printf("%s\n", result);

    // Free dynamically allocated memory
    free(result);

    return 0;
}
