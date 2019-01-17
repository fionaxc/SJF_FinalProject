#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARR_SIZE(arr) ( sizeof((arr)) / sizeof((arr[0])) )

typedef struct
{
	char name[N];
} user;


typedef struct
{
	 user u;
   lesson l;
   unsigned int wpm; //words per minute
   float accuracy; //words
} session;

char ** getWords(char * story);
void startGame(char ** dict);
void store(char * name, char * level, int score);
