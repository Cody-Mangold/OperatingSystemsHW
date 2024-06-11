#include "pslibrary.h"



/*


Assignment 2
OS cs 3733-003
Cody Mangold
kaj218

*/

int myCounter(char* myStr, char toFind)
{
  int i = 0;
  int foundCount = 0;
  
  while (myStr[i] != '\0')
  {
        if(myStr[i] == toFind)
          foundCount++;
          
      i++;
  }
  return foundCount;

};


int main ( int argc, char* argv[])
{
  if (argc < 8)
    {
      printf("error, not enough Parameters");
      exit(-1);
    }
  else if ( argc == 8)
  {
    printf("CS 3733 / Assignment 2 / written by Cody Mangold / kaj218\n");
  }
    
  int q = atoi(argv[1]);
  int x1 = atoi(argv[2]);
  int y1 = atoi(argv[3]);
  int z1 = atoi(argv[4]);
  int x2 = atoi(argv[5]);
  int y2 = atoi(argv[6]);
  int z2 = atoi(argv[7]);
  
  int total = x1+x2+ y1 +y2 +z1+z2;
  
  char s1[total];
  char s2[total];
  float avg;
  float cpuUsage;
  int i = 0;
  
  while ( i < 4)
  {
    switch(i){
    
      case 0:
      printf("\nScheduler FCFS:\n");
      fcfs(s1,s2,x1,y1,z1,x2,y2,z2);
      break;
      
      case 1:
      printf("\nScheduler SJF:\n");
      sjf(s1,s2,x1,y1,z1,x2,y2,z2);
      break;
  
      case 2:
      printf("\nScheduler PSJF:\n");
      psjf(s1,s2,x1,y1,z1,x2,y2,z2);
      break;
      
      case 3:
      printf("\nSchedule RR:\n");
      rr(s1,s2,q,x1,y1,z1,x2,y2,z2);
      break;
      
      default:
      
      printf("error in switch statement");
      break;
      
  }
      
  
  
  int readyCount1 = myCounter(s1, 'r');
  int readyCount2 = myCounter(s2, 'r');
  int runningCount1 = myCounter(s1,'R');
  int runningCount2 = myCounter(s2,'R');
  

  avg = ((float)(readyCount1+readyCount2))/2;
  
  
  
  if (strlen(s1) > strlen(s2))
    {
    cpuUsage = ((float)(runningCount1 + runningCount2)) / strlen(s1);
    }
  else
  {
  cpuUsage = ((float)(runningCount1 + runningCount2) )/ strlen(s2);
  }
  
  printf("%s\n", s1);
  printf("%s\n", s2);
  
  printf("%d %d %0.1f %0.5f\n", readyCount1, readyCount2, avg, cpuUsage);
  i++;

}
  

return 0;

}