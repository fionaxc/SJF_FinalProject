#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define ARR_SIZE(arr) ( sizeof((arr)) / sizeof((arr[0])) )


char ** getWords(char * story);
void store(char * name, int score);
void getRandomWord(char ** dict, char * chosenWord);
void startGame(char ** dict);
