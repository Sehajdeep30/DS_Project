#ifndef PROFILES_H
#define PROFILES_H

// Define the profile structure
typedef struct profile {
    char* username;
    int* scores;
    int highestScore;
    struct profile* next;
} Profile;

Profile* createProfile(const char* username, int numScores);
void writeProfileToFile(Profile* profile, const char* filename);
Profile* readProfilesFromFile(const char* filename);
void freeProfileList(Profile* head);
void updateProfile(Profile* profile, double elapsed_time);

#endif /*PROFILES_H*/
