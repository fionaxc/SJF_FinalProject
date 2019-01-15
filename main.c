#include "pages.h"

int main() {

    while (1) {

        // struct to store size of terminal;
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        print_menu(w.ws_row);

        char buffer;
        get_input(&buffer);

        if (buffer == '1') { // start new game
            // printf("you have chosen to start a new game");
            print_levels(w.ws_row);
            get_input(&buffer);

            // level selections
            if (buffer == '1') { // easy

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
