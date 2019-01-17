#include "leaderboard.h"

void print_list(struct leaderboard * main){

  struct leaderboard * pointer = main;
  printf("# | \n");
  while(pointer != NULL){

    printf("%d | %s -- %d\n", pointer -> curr_pos, pointer -> name, pointer -> typing_speed);
    pointer = (pointer -> next);

  }

}

struct leaderboard * insert_new(struct leaderboard * main, char * new_name, int new_speed){

  struct leaderboard * curr = main;
  struct leaderboard * new_person = malloc(sizeof(struct leaderboard));
  new_person -> name = new_name;
  new_person -> typing_speed = new_speed;
  int pos = 1;

//if the new data is the first to be put in
  if (curr == NULL){

    printf("First! \n");
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
    return new_person;

  }

  pos = pos + 1;
  struct leaderboard * temp = curr;
  struct leaderboard * prev = curr;
  curr = curr -> next;

  while (curr != NULL){

    if (new_speed > curr -> typing_speed){

      new_person -> curr_pos = pos;
      curr = shift_pos(curr);
      new_person -> next = curr;
      prev -> next = new_person;
      return temp;

    }
    if (new_speed == curr -> typing_speed){

      new_person -> curr_pos = pos;
      new_person -> next = curr;
      prev -> next = new_person;
      return temp;

    }
    pos = pos + 1;
    prev = curr;
    curr = curr -> next;

  }
  return NULL;

}

struct leaderboard * shift_pos(struct leaderboard * old_pointer){

  struct leaderboard * temp = old_pointer;
  while(old_pointer != NULL){

    old_pointer -> curr_pos = old_pointer -> curr_pos + 1;
    old_pointer = old_pointer -> next;

  }

  return old_pointer;

}


struct leaderboard * free_list(struct leaderboard * main){

  struct leaderboard * leaderboard = malloc(sizeof(struct leaderboard));
  struct leaderboard * pointer = main;
  struct leaderboard * prev = malloc(sizeof(struct leaderboard));
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

int main(){

  struct leaderboard * lb = malloc(sizeof(struct leaderboard));
  lb = NULL;

  lb = insert_new(lb, "char * new_name", 100  );
  print_list(lb);
  lb = insert_new(lb, "char * new_nam", 101  );
  print_list(lb);
  //lb = insert_new(lb, "char * new_na", 190  );
  //lb = insert_new(lb, "char * new_n", 8  );
  //lb = insert_new(lb, "char * new", 4 );
  print_list(lb);


}
