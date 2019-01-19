#include "pages.h"

// union semun {		/*  */
//     int     val;		/* value for SETVAL */
//     struct  semid_ds *buf;  /* buffer for IPC_STAT & IPC_SET */
//     u_short *array;         /* array for GETALL & SETALL */
// };

void print_menu(int term_size) {
    printf("WELCOME TO THE TYPING GAME BY FIONA, SOOJIN, AND JOYCE\n\nPress the corresponding number key to select menu items\n\n1) Start New Game\n2) View Leaderboard\n3) Exit\n");
    fill_screen(term_size, 8);
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
    *buffer_pt = fgetc(stdin);
    // change to normal terminal setting
    system("/bin/stty cooked");
}

void create_sem() {
    key_t key;
    key = ftok("makefile", 'a');
    //create semaphore
    int sfd;
    sfd = semget(key, 1, IPC_CREAT | IPC_EXCL | 0644);
    if (sfd == -1) {
        printf("semaphore error %d: %s\n", errno, strerror(errno));
    }
    //sets value of semaphore
    union semun mdata;
    mdata.val = 1;
    int s = semctl(sfd, 0, SETVAL, mdata);
    // printf("sem val: %d\n", semctl(sfd, 0, GETVAL, mdata));
    if (s == -1) {
        printf("semaphore error %d: %s\n", errno, strerror(errno));
    }
}

void rm_sem() {
    //remove semaphore
    int sfd;
    key_t key = ftok("makefile", 'a');
    sfd = semget(key, 1, 0);
    struct sembuf buffer;
    //down the semaphore
    buffer.sem_op = -1;
    buffer.sem_num = 0;
    buffer.sem_flg = SEM_UNDO;
    semop(sfd, &buffer, 1);
    semctl(sfd, 0, IPC_RMID);
}

void print_options(int term_size) {
    printf("Which text would you like to play?\n");
    printf("1) Little Red Riding Hood\n");
    printf("2) Hamlet Soliloquy\n");
    printf("3) Random Long Words in English\n");
    fill_screen(term_size, 5);
}
