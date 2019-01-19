#include "typing.h"
#include "pages.h"

//stores the newest score in allscores.txt file
void store(char * name, int score){
  FILE * f = fopen("allscores.txt", "a");
  fprintf(f, "%d\n%s", score, name);
  fclose(f);
}

int arrLength(char ** dict){
  int length = 0;
  int k = 0;
  for(k= 0; dict[k] != 0; ++k);
  length = k;
  return length;
}

void getRandomWord(char ** dict, char * chosenWord){
  int length = arrLength(dict);
  sprintf(chosenWord, "%s", dict[rand() % length]);
}

//Get the words from chosen story
//input: file name, easy.txt, medium.txt, or hard.txt
char ** getWords(char * story){
  FILE * f = fopen(story, "r");
  if(f == 0){
    printf("Please input a valid story\n");
    exit(1);
  }
  //put lines into an array of strings
  char line[512];
  char ** dict = malloc(2048 * sizeof(char *));
  int i = 0;
  while (fgets(line, sizeof(line), f)){
    line[strlen(line)-1]=0;
    dict[i] = malloc(strlen(line)+1);
    strcpy(dict[i], line);
    i++;
  }

  fclose(f);
  return dict;
}


//ACTUAL TYPING GAME FUNCTION
void startGame(char ** dict, char * name){
  key_t key = ftok("makefile", 'a');

  //CHOOSING LEVEL OF DIFFICULTY; VARIES ON TIME ALLOCATED FOR GAME
  printf("Choose your level of difficulty:\n");
  printf("1) Easy (60 seconds)\n");
  printf("2) Medium (45 seconds)\n");
  printf("3) Hard (30 seconds)\n");
  printf("4) Exit Game\n");

  char * s_default="You did not press a valid key; Default level is Medium";

  char level;
  get_input(&level);
  int time_limit;
  if(level == '1'){
    time_limit = 60;
  }
  else if(level == '2'){
    time_limit = 45;
  }
  else if(level == '3'){
    time_limit = 30;
  }
  else if(level == '4'){
    return;
  }
  else{
    printf("%s\n", s_default);
    time_limit = 45;
  }

  //STARTING ACTUAL GAME
  if(dict == 0){
    printf("Please input a valid dictionary\n");
    return;
  }

  printf("Ok! The game is about to start...\n");
  fflush(stdout);
  sleep(1);
  printf("Ready\n");
  fflush(stdout);
  sleep(1);
  printf("Set\n");
  fflush(stdout);
  sleep(1);
  printf("GO!\n");

  srand(time(0));

  time_t start = time(0);
  time_t current = 0;

  char word[100];
  char input[100];
  float accuracy;
  float wpm;
  int score = 0;
  int totalletters = 0;
  int totalwords = 0;

  while (current < time_limit){
    getRandomWord(dict, word);
    printf("[%s]\n--> ", word);
    totalletters += strlen(word);
    scanf("%s", input); //get the user's input word
    for(int i = 0; input[i] != 0 && word[i] != 0; ++i){
      if(input[i] == word[i]){
        score++; //increase score by 1 for each correct letter
      }
    }
    totalwords++;
    current = time(0) - start; //update current time
    printf("Current Score: %d | Current Time: %ld s \n", score, current);
  }

  accuracy = (score / ((double) totalletters)) * 100;
  wpm = (totalwords)/((double)time_limit/60);

  printf("Yay you have completed this game!\nYour score is %d.\n", score);
  printf("Words per minute: %.2f | Accuracy: %.2f\n",wpm, accuracy);

  sleep(5);
  down_sem(key);
  store(name, score);
  up_sem(key);
  sleep(1);

}
