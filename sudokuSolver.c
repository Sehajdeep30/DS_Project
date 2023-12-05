#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

#include "sudokuSolver.h"


char pattern[] =
"+---+---+---+---+---+---+---+---+---+ \n\
|   |   |   |   |   |   |   |   |   | \n\
+---+---+---+---+---+---+---+---+---+ \n\
|   |   |   |   |   |   |   |   |   | \n\
+---+---+---+---+---+---+---+---+---+ \n\
|   |   |   |   |   |   |   |   |   | \n\
+---+---+---+---+---+---+---+---+---+ \n\
|   |   |   |   |   |   |   |   |   | \n\
+---+---+---+---+---+---+---+---+---+ \n\
|   |   |   |   |   |   |   |   |   | \n\
+---+---+---+---+---+---+---+---+---+ \n\
|   |   |   |   |   |   |   |   |   | \n\
+---+---+---+---+---+---+---+---+---+ \n\
|   |   |   |   |   |   |   |   |   | \n\
+---+---+---+---+---+---+---+---+---+ \n\
|   |   |   |   |   |   |   |   |   | \n\
+---+---+---+---+---+---+---+---+---+ \n\
|   |   |   |   |   |   |   |   |   | \n\
+---+---+---+---+---+---+---+---+---+ ";

int indexor[9][9];
int sudoku[9][9];

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

#include <stdio.h>

// Function to check if a number can be placed at a specific position in the Sudoku grid
int isSafe(int sudoku[9][9], int row, int col, int num) {
    // Check if the number is not present in the same row and column
    for (int x = 0; x < 9; x++) {
        if (sudoku[row][x] == num || sudoku[x][col] == num) {
            return 0; // Not safe
        }
    }

    // Check if the number is not present in the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[i + startRow][j + startCol] == num) {
                return 0; // Not safe
            }
        }
    }

    return 1; // Safe
}

// Function to check if the Sudoku grid is valid
int isSudokuValid(int sudoku[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            // Check if the current cell is not empty
            if (sudoku[row][col] != 0) {
                // Check if the current number can be placed in the current cell
                if (!isSafe(sudoku, row, col, sudoku[row][col])) {
                    return 0; // Not valid
                }
            }
        }
    }
    printf("Sudoku is valid :)");
    return 1; // Valid
}

char* returnSub(int start_index, int end_index,char * pattern) {
    char* sub_string = (char*)malloc(end_index - start_index + 1); // +1 for null terminator
    strncpy(sub_string, pattern + start_index, end_index - start_index);
    sub_string[end_index - start_index] = '\0';
    return sub_string;
}


char* sudokuString(int sudoku[9][9]) {
    const char* substring = "   ";
    const char* ptr = pattern;
    char* sudoku_string = (char*)calloc(1,strlen(pattern) + 1); // +1 for null terminator
    strcpy(sudoku_string, "");

    int i = 0, start_index = 0, end_index = 0, arr_x = 0, arr_y = 0;

    while ((ptr = strstr(ptr, substring)) != NULL) {

        end_index = ptr - pattern;
        indexor[arr_x][arr_y] = end_index;
        strcat(sudoku_string, returnSub(start_index, end_index,pattern));
                
        if(sudoku[arr_x][arr_y] != 0){
            
            char number_char = (char)(sudoku[arr_x][arr_y] + '0');
            strncat(sudoku_string,&number_char, 1);
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

void removeChar(char *str, char target) {
    char *ptr = strchr(str, target);
    if (ptr != NULL) {
        strcpy(ptr, ptr + 1);
    }
}

char *newString(int cursor, char *str) {
    removeChar(str, 'X'); // TODO

    char *new_string = (char *)malloc(strlen(str) + 3); // +3 for two spaces and null terminator
    strcpy(new_string, "");

    int arr_x = cursor / 9;
    int arr_y = cursor % 9;
    char number_char;

    if (sudoku[arr_x][arr_y] != 0) {
        number_char = (char)(sudoku[arr_x][arr_y] + '0');
    } else {
        number_char = 'X';
    }

    int middle_index = indexor[arr_x][arr_y] - 1; // Index of the middle blank space

    // Calculate the position to align 'X' in the middle of three spaces
    int align_index = middle_index - (middle_index % 3);

    // Copy the substring before the middle blank space
    strncat(new_string, str, align_index);

    // Align 'X' in the middle
    strcat(new_string, " ");
    strcat(new_string, &number_char);
    strcat(new_string, " ");

    // Copy the substring after the middle blank space
    strcat(new_string, str + align_index + 3);

    return new_string;
}

double sudokuFill(int sudoku[9][9]) {
    clock_t start_time = clock();
    sudokuChoose();
    char *str = sudokuString(sudoku);
    int cursor = 1, key = 0, arr_x = 0, arr_y = 0;

    while (isSudokuValid(sudoku) != 1) {
        system("cls"); // Clear the console screen

        printf("\nUSE THE ARROW KEYS TO MOVE:\n");
        printf("%s", str);
        printf("\nPress x to Quit Game\n");

        key = _getch();

        if (key == 'x' || key == 'X') {
            break;
        }

        if (key == 224) {
            key = _getch(); // Read the extended key code

            switch (key) {
            case 72:
                if (cursor > 9) {
                    cursor -= 9;
                }
                break;

            case 80:
                if (cursor < 73) {
                    cursor += 9;
                }
                break;

            case 75:
                if (cursor % 9 != 1) {
                    cursor -= 1;
                }
                break;

            case 77:
                if (cursor % 9 != 0) {
                    cursor += 1;
                }
                break;

            default:
                printf("\nInvalid key, retry");
                continue;
            }

            arr_x = cursor / 9;
            arr_y = cursor % 9;

            if (0 < key && key <= 9) {
                sudoku[arr_x][arr_y] = (int)(key - '0');
            }

            str = newString(cursor, str);
        }
    }
    clock_t end_time = clock();
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;
    double score = (elapsed_time/600)*100;
    printf("score is %lf", score);
    return score;
}
