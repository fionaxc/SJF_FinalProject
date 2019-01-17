#include "typing.h"

//stores the newest score in allscores.txt file
void store(char * name, int score){
  FILE * f = fopen("allscores.txt", "a");
  fprintf(f, "%d\n%s", score, name);
  fclose(f);
}

void getRandomWord(char ** dict, char * chosenWord){
  int len = 0;
  int i = 0;
  for(i = 0; dict[i] != NULL; ++i);
  len = i;
  i = rand()%len;
  sprintf(chosenWord, "%s", dict[i]);
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
void startGame(char ** dict){
  printf("What is your name?\n");
  char name[256];
  fgets(name, 256, stdin);

  //CHOOSING LEVEL OF DIFFICULTY; VARIES ON TIME ALLOCATED FOR GAME
  printf("Choose your level of difficulty:\n");
  printf("1) Easy (60 seconds)\n");
  printf("1) Medium (60 seconds)\n");
  printf("1) Easy (60 seconds)\n");
  char * s_easy="Easy (60 seconds): Press 1";
  char * s_medium="Medium (45 seconds): Press 2";
  char * s_hard="Hard (30 seconds): Press 3";
  char * s_default="You did not press a valid key; Default level is Medium";

  printf("%s\n %s\n %s\n %s\n", intro, s_easy, s_medium, s_hard);
  char level[256];
  fgets(level, 256, stdin);
  int time_limit;
  if(*level == '1'){
    time_limit = 60;
  }
  else if(*level == '2'){
    time_limit = 45;
  }
  else if(*level == '3'){
    time_limit = 30;
  }
  else{
    printf("%s\n", s_default);
    time_limit = 45;
  }

  printf("%d\n", time_limit);
  //STARTING ACTUAL GAME
  if(dict == 0){
    printf("Please input a valid dictionary\n");
    return;
  }
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
    printf("%s | Current Score: %d | Current Time: %ld s \n", name, score, current);
  }
  accuracy = (score / ((double) totalletters)) * 100;
  wpm = ((double)totalwords)/(current/60);
  printf("Yay you have completed this game!\nYour score is %d.", score);
  printf("Words per minute: %.2f | Accuracy: %.2f\n",wpm, accuracy);
  sleep(3);
  store(name, score);
  sleep(1);
}
