#include "pages.h"

int main() {

    while (1) {
        print_menu();

        // send all keystrokes directly to stdin (read only one char)
        system("/bin/stty raw");
        // get user selection
        char buffer;
        buffer = fgetc(stdin);
        // change to normal terminal setting
        system ("/bin/stty cooked");

        if (buffer == '3') { //exit is selected
            exit(1);
        }
    } // end while

    return 0;
}
