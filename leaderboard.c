#include <stdio.h>
#include <stdlib.h>

struct leaderboard{char* name; double typing_speed; double date; struct* leaderboard next;};

struct leaderboard main;
struct * leaderboard pointer = *main;

void print_list(){

  int counter = 0;
  printf(" # | \n")
  while(pointer != NULL){

    printf("%d | %s -- %lf...%lf\n", counter, pointer -> name, pointer -> typing_speed, pointer -> date );
    pointer = (pointer -> next);
    counter ++;

  }

}

struct leaderboard * insert_new(char * new_name, double new_speed, double new_date ){

}

struct leaderboard * free_list(){

  struct node * prev = malloc(sizeof(struct leaderboard));
  prev = main;
  main = main -> next;

  while(main != NULL){

    free(prev);
    prev = main;
    main = main -> next;

  }

  free(prev );
  prev = main;

  return prev;

}

