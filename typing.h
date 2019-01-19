#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <math.h>

char ** getWords(char * story);
void store(char * name, int score);
int arrLength(char ** dict);
void getRandomWord(char ** dict, char * chosenWord);
void startGame(char ** dict, char * name);
