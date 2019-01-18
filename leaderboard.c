#include "leaderboard.h"

void print_list(struct leaderboard * main){

  if (main == NULL) {
      printf("Leaderboard is currently empty.\n");
  }
  else {
      struct leaderboard * pointer = main;
      printf("Leaderboard\n");
      printf("# | \n");
      int pos = 1;
      int prev;
      while(pointer != NULL){
        printf("%d | %s -- %d\n", pos, pointer -> name, pointer -> score);
        prev = pointer -> score;
        pointer = pointer -> next;
        if (pointer != NULL && pointer -> score != prev) { pos++;}
    }
}

}

struct leaderboard * insert_new(struct leaderboard * main, char * new_name, int new_score){

  struct leaderboard * curr = main;
  struct leaderboard * new_person = malloc(sizeof(struct leaderboard));
  new_person -> name = malloc(sizeof(char) * 256);
  strcpy(new_person -> name, new_name);
  new_person -> score = new_score;

  // if the new data is the first to be put in
  // or
  // if the new entry is the top entry or is equal to the top entry.
  if (curr == NULL || curr -> score <= new_score){

    // printf("First! \n");
    new_person -> next = curr;
    return new_person;
  }

  struct leaderboard * temp = curr;
  struct leaderboard * prev = curr;
  curr = curr -> next;

  while (curr != NULL){

    if (new_score >= curr -> score){
      new_person -> next = curr;
      prev -> next = new_person;
      return temp;
    }

    prev = curr;
    curr = curr -> next;

  }
  prev -> next = new_person;
  new_person -> next = NULL;
  return temp;

}

struct leaderboard * free_list(struct leaderboard * main){

  struct leaderboard * next;

  while(main != NULL){
    next = main -> next;
    free(main -> name);
    free(main);
    main = next;

  }

  return main;

}

struct leaderboard * create_lb(struct leaderboard * main) {
    FILE * f = fopen("allscores.txt", "r");
    char next_line[256];
    char c = 0; // score
    int score = 0;
    while(fgets(next_line, 256, f)) {
        // printf("%s", next_line);
        if (strcmp(next_line, "\n")) {
            if (c) { // name
                next_line[strlen(next_line) - 1] = '\0';
                // printf("inserting %s: %d\n", next_line, score);
                main = insert_new(main, next_line, score);
                c = 0;
            }
            else { // score
                score = atoi(next_line);
                c = 1;
            }
        }
    }
    return main;
}

void print_lb() {
    struct leaderboard * lb = NULL;
    lb = create_lb(lb);
    print_list(lb);
    free_list(lb);
}
