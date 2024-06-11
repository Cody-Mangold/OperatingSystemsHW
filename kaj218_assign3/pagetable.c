#include "pagetable.h"
#include "phypages.c"
/* 
Cody Mangold - kaj218
CS-3733-003
Assignment 3: Paging
*/


int LRU(PTE* pageTable, int tableSize)
{
int positionLRU;
int lowestRef = pageTable[1].refCount;
int counter;


for(counter = 0; counter < tableSize; counter++)
  {
  if(pageTable[counter].status == VALID)
    {
    lowestRef = pageTable[counter].refCount;
    positionLRU = counter;
    break;
    }
  }
for(counter = positionLRU; counter < 32; counter++)
{
  if(pageTable[counter].status == VALID && pageTable[counter].refCount < lowestRef)
  {
    lowestRef = pageTable[counter].refCount;
    positionLRU = counter;
  }
}
/*

for(counter = 0; counter < tableSize; counter++)
  {
  if(pageTable[counter].status == VALID)
    {
    lowestRef = counter;
    break;
    }
  }

for(counter = 0; counter < tableSize; counter++)

  {
  if(pageTable[counter].status == VALID )
    {
    continue;
    }
  
  else if (pageTable[counter].refCount < pageTable[lowestRef].refCount)
    {
    lowestRef = counter;
    }
    
  }
  */
  
  //printf("here we are\n\n\n");
  pageTable[positionLRU].status = NONVALID;
  int retVal = pageTable[positionLRU].frameNum;
  
  return retVal;
}


