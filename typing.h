#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
