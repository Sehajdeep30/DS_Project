#include "headers.h"

struct Profile {
    int* scores;
    int highestScore;
    char* username;
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
    while (*(profiles->username) != username) {
        if (profiles->username == 0) {
            printf("Profile with username %d not found.\n", username);
            return;
        }
        profiles++;
    }

    // Display the selected profile
    printf("\nProfile Information:\n");
    printf("Username: %d\n", selectedProfile->username);
    printf("Score: %.2f\n", selectedProfile->scores);
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
                    struct Profile* profiles = readProfilesFromFile("profiles.dat");
                    displayProfiles(profiles);
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
