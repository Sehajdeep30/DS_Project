#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

#include "profiles.h"

// Function to create a new profile
Profile* createProfile() {
    char * username = (char)malloc(25);
    strcat(username,"");
    printf("Enter the u sername: ");
    scanf("%s",username);
    Profile* profile = (Profile*)malloc(sizeof(Profile));
    if (!profile) {
        perror("Error creating profile");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for scores
    profile->scores = (int*)malloc(numScores * sizeof(int));
    if (!profile->scores) {
        perror("Error allocating memory for scores");
        exit(1);
    }

    // Initialize scores to 0
    for (int i = 0; i < numScores; i++) {
        profile->scores[i] = 0;
    }

    profile->highestScore = 0;

    // Allocate memory for username
    profile->username = strdup(username);
    if (!profile->username) {
        perror("Error allocating memory for username");
        exit(EXIT_FAILURE);
    }
    printf("Profile generated.")
    return profile;
}

// Function to write a profile to a file
void writeProfileToFile(Profile* profile, const char* filename){
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    // Write the profile structure to the file
    fwrite(profile, sizeof(Profile), 1, file);

    fclose(file);
}

// Function to read profiles from a file and create a linked list
Profile* readProfilesFromFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    Profile* head = NULL;
    Profile* current = NULL;

    while (!feof(file)) {
        Profile* newProfile = (Profile*)malloc(sizeof(Profile));
        if (!newProfile) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        size_t bytesRead = fread(newProfile, sizeof(Profile), 1, file);

        if (bytesRead == 1) {
            newProfile->next = NULL;

            if (head == NULL) {
                head = newProfile;
                current = newProfile;
            } else {
                current->next = newProfile;
                current = newProfile;
            }
        } else {
            free(newProfile); // Free memory if read was unsuccessful
        }
    }

    fclose(file);
    return head;
}

// Function to free the memory allocated for the linked list
void freeProfileList(Profile* head) {
    while (head != NULL) {
        Profile* temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to update a profile with the current score
void updateProfile(Profile* profile, double elapsed_time) {
    double score = (fabs(elapsed_time - 600)/600)*100;

    // Update the UserProfile structure with the current score
    for (int i = 9; i >= 1; i--) {
        profile->scores[i] = profile->scores[i - 1];
    }
    profile->scores[0] = score;

    // Check if the current score is the highest
    if (score > profile->highestScore) {
        profile->highestScore = score;
    }

    profile->next = NULL;

    // Write the UserProfile structure to a file
    writeProfileToFile(profile, "profiles.dat");
}
