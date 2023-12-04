#ifndef PROFILES_H
#define PROFILES_H


struct Profile* createProfile(const char* username, int numScores);
void writeProfileToFile(struct Profile* profile, const char* filename);
struct Profile* readProfilesFromFile(const char* filename);
void freeProfileList(struct Profile* head);
void updateProfile(struct Profile* profile, double elapsed_time);


#endif /*PROFILES_H*/