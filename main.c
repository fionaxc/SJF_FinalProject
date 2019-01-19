#include "pages.h"
#include "typing.h"
#include "leaderboard.h"

int main(int argc, char ** argv) {

    char buffer = '\0';
    while (1) {

      // struct to store size of terminal;
      struct winsize w;
      ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
      key_t key = ftok("makefile", 'a');
      print_menu(w.ws_row);
      while (buffer!='1' && buffer!='2' && buffer!='3') {
          get_input(&buffer);
      }

      if (buffer == '1') { // start new game
          // printf("you have chosen to start a new game");
          //print_levels(w.ws_row);

          print_options(w.ws_row);
          while (buffer!='1' && buffer!='2' && buffer!='3') {
              get_input(&buffer);
          }
          char * story;
          // text selection
          if (buffer == '1') {
            story = "lrrh.txt";
          }
          if (buffer == '2'){
            story = "hamlet.txt";
          }
          if (buffer == '3'){
            story = "longwords.txt";
          }
          char ** dict = getWords(story);
          printf("Ok! The game will start...");
          sleep(1);
          printf("NOW!\n");
          sleep(1);
          create_sem(key);
          startGame(dict);
      }

      else if (buffer == '2') {
          print_lb();
          printf("\n\npress any key to go back to home\n");
          get_input(&buffer);

          //get_input(&buffer);

      }
      else if (buffer == '3') { // exit is selected
          rm_sem(key);
          exit(1);
      }

    } // end while

    return 0;
}
