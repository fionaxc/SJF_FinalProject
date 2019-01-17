#include <stdio.h>
#include <stdlib.h>

struct leaderboard{char* name; int curr_pos; int typing_speed; struct leaderboard * next;};

void print_list(struct leaderboard * main);

struct leaderboard * insert_new(struct leaderboard * main ,char * new_name, int new_speed );

struct leaderboard * shift_pos(struct leaderboard * old_pointer);

struct leaderboard * free_list(struct leaderboard * main);
