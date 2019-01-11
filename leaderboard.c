#include <stdio.h>
#include <stdlib.h>

struct leaderboard{char* name; int curr_pos; double typing_speed; double date; struct* leaderboard next;};

struct leaderboard main = NULL;

void print_list(){

  struct leaderboard * pointer = *main;
  printf(" # | \n")
  while(pointer != NULL){

    printf("%d | %s -- %lf...%lf\n", pointer -> curr_pos, pointer -> name, pointer -> typing_speed, pointer -> date );
    pointer = (pointer -> next);
    counter ++;

  }

}

struct leaderboard * increase_by_one (struct leaderboard * pointer){

  struct leaderboard * pointer = *main;
  while(pointer != NULL){

    pointer -> curr_pos = curr_pos + 1;

  }

}

struct leaderboard * insert_new(char * new_name, double new_speed, double new_date ){

  struct leaderboard * curr = *main;
  struct leaderboard * new_person = malloc(sizeof(struct leaderboard));
  new_person -> name = new_name;
  new_person -> typing_speed = new_speed;
  new_person -> date = new_date;
  int curr_pos = 1;

  if (*curr == NULL){

    new_person -> next = curr;
    main = new_person;
    return curr;

  }
  if ((curr -> typing_speed) <= new_speed){

    if ((curr -> typing_speed) < new_speed){

      new_speed = curr_pos;

    }

  }
  while (curr != NULL){



  }

}

struct leaderboard * free_list(){

  struct * leaderboard pointer = *main;
  struct node * prev = malloc(sizeof(struct leaderboard));
  prev = pointer;
  pointer = pointer -> next;

  while(pointer != NULL){

    free(prev);
    prev = pointer;
    pointer = pointer -> next;

  }

  free(prev );
  prev = pointer;

  return prev;

}
