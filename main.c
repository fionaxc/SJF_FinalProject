#include "pages.h"
#include "typing.h"
#include "leaderboard.h"

int main(int argc, char ** argv) {

    while (1) {

        char buffer = '\0';
        // struct to store size of terminal;
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        key_t key = ftok("makefile", 'a');
        print_menu(w.ws_row);
        while (buffer!='1' && buffer!='2' && buffer!='3') {
            get_input(&buffer);
        }

        int f = fork();

        if (f) {
            int status;
            wait(&status);
            if (WEXITSTATUS(status) == 3) {
                exit(1);
            }
        }

        else {

            if (buffer == '1') { // start new game

                char * name = get_username();
                print_options(w.ws_row,name);
                buffer = '\0';
                while (buffer!='1' && buffer!='2' && buffer!='3' && buffer!='4' && buffer!='5') {
                    get_input(&buffer);
                }
                char * story;
                // text selection
                if (buffer == '1') {
                    story = "text/lrrh.txt";
                }
                if (buffer == '2'){
                    story = "text/hamlet.txt";
                }
                if (buffer == '3'){
                    story = "text/h_and_g.txt";
                }
                if (buffer == '4'){
                    story = "text/longwords.txt";
                }
                if (buffer != '5'){
                    char ** dict = getWords(story);
                    create_sem(key);
                    startGame(dict, name);
                }

            }

            else if (buffer == '2') {
                print_lb();
                printf("\n\nPress any key to go back to home page\n");
                get_input(&buffer);

                //get_input(&buffer);
            }
            else if (buffer == '3') { // exit is selected
                rm_sem(key);
                exit(1);
            }
        }
    } // end while

    return 0;
}
