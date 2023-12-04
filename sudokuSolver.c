#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include "sudokuSolver.h"
#include "sudokuStore.h"


void removeChar(char *str, char target) {
    char *ptr = strchr(str, target);
    if (ptr != NULL) {
        strcpy(ptr, ptr + 1);
    }
}

char *newString(int cursor, char *str) {
    removeChar(str, 'X');

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

    while (1) {
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
    return elapsed_time;
}
