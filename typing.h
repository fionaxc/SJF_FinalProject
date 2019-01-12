#define NLINES 5
#define WIDTH 60
#define SCRWIDTH 80
#define SCRHEIGHT 24
#define PAGE WIDTH*NLINES


typedef struct
{
	char name[N];
}user;


typedef struct
{
	 user u;
   lesson lsn;
   unsigned int wpm;
   float accuracy;
}session;

void beginSession(void);
void displayResults(void);
