#define READY 0
#define RUNNING 1
#define WAITING 2
#define DONE 3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*


Assignment 2
OS cs 3733-003
Cody Mangold
kaj218

*/

static char stateChars[] = {'r','R','w','\0'};


void fcfs(char *s1, char *s2, int x1, int y1, int z1,int x2, int y2, int z2);
void sjf(char *s1, char *s2, int x1, int y1, int z1,int x2, int y2, int z2);
void psjf(char *s1, char *s2, int x1, int y1, int z1,int x2, int y2, int z2);
void rr(char *s1, char *s2,int quantum, int x1, int y1, int z1,int x2, int y2, int z2);



