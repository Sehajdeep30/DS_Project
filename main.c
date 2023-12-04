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

struct Profile* createProfile(const char* username, int numScores);
void writeProfileToFile(struct Profile* profile, const char* filename);
struct Profile* readProfilesFromFile(const char* filename);
void freeProfileList(struct Profile* head);
void updateProfile(struct Profile* profile, double elapsed_time);

struct Profile {
    int username;
    int* scores;
    int highestScore;
    struct Profile* next;
};

void displayProfiles(struct Profile* profiles) {
    if (!profiles) {
        printf("No profiles available.\n");
        return;
    }

    int username;
    printf("Enter profile number (username): ");
    scanf("%d", &username);
    

    // Search for the profile with the specified username
    struct Profile* selectedProfile = NULL;
    while (profiles != NULL && profiles->username != username) {
        if (profiles->next == NULL) {
            printf("Profile with username %d not found.\n", username);
            return;
        }
        profiles = profiles->next;
    }

    // Display the selected profile
    printf("\nProfile Information:\n");
    printf("Username: %d\n", selectedProfile->username);
    printf("Highest Score: %.2f\n", selectedProfile->highestScore);

    // Add other profile data display as needed
}

int main() {
    int choice;

    do {
        // Display the menu
        printf("\nMenu:\n");
        printf("1. Solve Sudoku\n");
        printf("2. View Profiles\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");

        // Get user choice
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                {
                    int sudoku[9][9];  // Placeholder for Sudoku puzzle
                    sudokuFill(sudoku);
                }
                break;
            case 2:
                {
                    const char* filename = "profiles.dat";  // Change the filename as needed
                    struct Profile* profiles = readProfilesFromFile(filename);
                    displayProfiles(profiles);
                    freeProfileList(profiles);  // Free memory allocated for the linked list
                }
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }

    } while (choice != 3);  // Continue the loop until the user chooses to exit

    return 0;
}
