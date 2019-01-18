#include "pages.h"
#include "typing.h"
#include "leaderboard.h"

int main(int argc, char ** argv) {

    char buffer;
    while (1) {

      // struct to store size of terminal;
      struct winsize w;
      ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
      print_menu(w.ws_row);
      get_input(&buffer);

      if (buffer == '1') { // start new game
          // printf("you have chosen to start a new game");
          //print_levels(w.ws_row);

          printf("Which text would you like to play?\n");
          printf("1) Little Red Riding Hood\n");
          printf("2) Hamlet Soliloquy\n");
          printf("3) Random Long Words in English\n");

          get_input(&buffer);
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
          startGame(dict);
      }

      else if (buffer == '2') {
          print_lb();
          printf("\n\npress any key to go back to home\n");
          system("/bin/stty raw");
          buffer = fgetc(stdin);
          system("/bin/stty cooked");

          //get_input(&buffer);

      }
      else if (buffer == '3') { // exit is selected
          exit(1);
      }

    } // end while

    return 0;
}
