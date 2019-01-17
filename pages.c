#include "pages.h"

void print_menu(int term_size) {
    printf("WELCOME TO THE TYPING GAME BY FIONA, SOOJIN, AND JOYCE\n\nPress the corresponding number key to select menu items\n\n1) Start New Game\n2) View Leaderboard\n3) Exit\n");
    fill_screen(term_size, 8);
}

void print_levels(int term_size) {
    printf("Select a level\n\n");
    printf("1) Easy\n2) Medium\n3) Hard\n");
    fill_screen(term_size, 6);
}

void fill_screen(int term_size, int content_size) {
    for (int i = 0; i < term_size - content_size; i++) {
        printf("\n");
    }
}

void get_input(char * buffer_pt) {
    // send all keystrokes directly to stdin (read only one char)
    system("/bin/stty raw");
    // get user selection
    *buffer_pt = '\0';
    while (*buffer_pt != '1' && *buffer_pt != '2' && *buffer_pt != '3') {
        *buffer_pt = fgetc(stdin);
    }
    // change to normal terminal setting
    system("/bin/stty cooked");
}
