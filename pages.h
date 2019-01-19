#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <errno.h>

#ifndef HOME_PAGE
#define HOME_PAGE
#define USERNAME_LEN 16
void print_menu(int term_size);
void fill_screen(int term_size, int content_size);
void get_input(char * buffer_pt);
void print_options(int term_size, char * name);
void create_sem(key_t key);
void up_sem(key_t key);
void down_sem(key_t key);
void rm_sem(key_t key);
char * get_username();

#endif
