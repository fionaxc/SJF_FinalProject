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
  int pos = 1;

//if the new data is the first to be put in
  if (*curr == NULL){

    new_person -> next = curr;
    new_person -> curr_pos = pos;
    curr = new_person;
    return curr;

  }
//if the new entry is the top entry or is equal to the top entry.
  if ((curr -> typing_speed) <= new_speed){

    new_person -> curr_pos = pos;
    if ((curr -> typing_speed) < new_speed){

      //Everyone gets shifted down one position
      new_person -> next = shift_pos(curr);

    }
    else{

      //No need to be shifted since the top are equal to each other.
      new_person -> next = curr;
    }
    curr = new_person;
    return curr;

  }

  struct leaderboard * curr = *main;

  while (curr != NULL){



  }

}

struct leaderboard * shift_pos(struct leaderboard * old_pointer){

  while(old_pointer != NULL){

    old_pointer -> curr_pos = old_pointer -> curr_pos + 1;
    old_pointer = old_pointer -> next;

  }

  return old_pointer;

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
