#include "pages.h"

int main(int argc, char ** argv) {

    while (1) {
      // struct to store size of terminal;
      struct winsize w;
      ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
      print_menu(w.ws_row);
      printf("WELCOME TO THE TYPING GAME BY FIONA, SOOJIN, AND JOYCE \n");

      char buffer;
      get_input(&buffer);

      if (buffer == '1') { // start new game
          // printf("you have chosen to start a new game");
          print_levels(w.ws_row);
          get_input(&buffer);
          printf("Which text would you like to play?\n");
          printf("Little Red Riding Hood --> Enter 1; \n");
          printf("Hamlet Soliloquy --> Enter 2; \n");
          printf("Random Long Words in English --> Enter 1; \n");

          char ** dict = 
          // level selections
          if (buffer == '1') { //

          }
      }

      if (buffer == '2') {
          printf("Leaderboard feature in progress\n");
          sleep(3);
      }
      if (buffer == '3') { // exit is selected
          exit(1);
      }

    } // end while

    return 0;
}
