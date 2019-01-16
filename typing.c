#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

//Get the words from chosen story
//input: file name, easy.txt, medium.txt, or hard.txt
char ** getWords(char * story){
  File * f = fopen(story, "r");
  if(f == 0){
    printf("Please input a valid story\n");
    exit(1);
  }
  char input[512];
  char ** dict = malloc(2048 * sizeof(char *));
  while (fgets(input, sizeof(input), f)){
    strcpy(dict[i], input);
  }
  fclose(f);
  return dict;
}

//stores the newest score in allscores.txt file
void store(char * name, char * level, int score){
  File * f = fopen("allscores.txt", "a");
  fprintf(f, "%s\n %s\n %d\n", name, level, score);
  fclose(f);
}

//ACTUAL TYPING GAME FUNCTION
void startGame(char ** dict){

  //CHOOSING LEVEL OF DIFFICULTY; VARIES ON TIME ALLOCATED FOR GAME
  char * intro="THE TYPING GAME BY FIONA, SOOJIN, AND JOYCE \n Choose your level of difficulty:";
  char * s_easy="Easy: Press 1";
  char * s_medium="Medium: Press 2";
  char * s_hard="Hard: Press 3";
  char * s_default="You did not press a valid key; Default level is Medium";

  printf("%s\n %s\n %s\n %s\n", intro, s_easy, s_medium, s_hard);
  char * level;
  int time_limit;
  getinput(&level);
  if(level == '1'){
    time_limit = 60;
  }
  else if(level == '2'){
    time_limit = 45;
  }
  else if(level == '3'){
    time_limit = 30;
  }
  else{
    printf("%s\n", s_default);
    time_limit = 30;
  }

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
  int score = 0;

  while (current < time_limit){ //currently easy level, CHANGE time later according to level
    randomWord(dict, word);
    printf("[%s]\n---------->\n", word);
    scanf("%s", input); //get the user's input word
    for(int i = 0; input[i] != 0 && word[i] != 0; ++i){
      if(input[i] == word[i]){
        score++; //increase score by 1 for each correct letter
      }
    }
    current = time(0) - start; //update current time
  }

  printf("Yay you have completed this game! This is your score [%d]\n", score);
  store(name, level, score); //WRITE THIS FUNCTION1!!!!!!!
  delay();
}
