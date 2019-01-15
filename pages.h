#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <errno.h>

#ifndef HOME_PAGE
#define HOME_PAGE
void print_menu(int term_size);
void print_levels(int term_size);
void fill_screen(int term_size, int content_size);
void get_input(char * buffer_pt);

#endif
