#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

#ifndef HOME_PAGE
#define HOME_PAGE
void print_menu(int term_size);
void fill_screen(int term_size, int content_size);
void get_input(char * buffer_pt);
void print_options(int term_size);
void create_sem();
void rm_sem();

#endif
