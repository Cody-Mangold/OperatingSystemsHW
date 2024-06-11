#include "phypages.c"
#include "pagetable.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* 
Cody Mangold - kaj218
CS-3733-003
Assignment 3: Paging
*/



int main(int argc, char* argv[])

{

if(argc <3)
{
printf("error, not enough parameters! Exiting\n");
return -1;
}

FILE* dataFile;
PTE pageTable[32];
FILE* writeFile;
 size_t lineHolder;
 uint64_t buffer;
 uint64_t pageNum;
 uint64_t offset;
 uint64_t frameNum;
 int pgFaults = 0;
 int freeFrameCount = 1;
 int refCounter=0;
 int lruCount = 0;
 if((dataFile = fopen(argv[1],"rb")) == NULL )
	{
	fprintf(stderr, "Error opening file: %s!\n",argv[1]);
	return -1;

	}
 //printf("we made it");
 if((writeFile = fopen(argv[2],"wb")) == NULL )
	{
	fprintf(stderr, "Error opening file: %s!\n",argv[1]);
	return -1;
	}
 
 


  while((lineHolder = fread(&buffer,sizeof(uint64_t),1L,	dataFile)) == 1)
	{
	if(lineHolder == 0 & !feof(dataFile))
		{
		fprintf(stderr, "Error reading next address\n");
		return -1;
		}
	
	pageNum = buffer >> 7;
//	printf("Page number: %d\n",pageNum);

	offset = buffer & 0x7f;
	
 /*
   if(pageTable[pageNum].status == NONVALID)
   {
   pgFaults++;
   }
     */ 
   if(pageTable[pageNum].status == VALID)
   {
   frameNum = pageTable[pageNum].frameNum;
   pageTable[pageNum].refCount = refCounter;
   refCounter++;
   //printf("we mdae it in valid test\n");
   }
   
   else if (freeFrameCount < 8)
   {
   frameNum = freeFrameCount;
   freeFrameCount++;
   pgFaults++;
   
   
   }
   
   else
   {
   //printf("I made it to the LRU");
   frameNum = LRU(pageTable,32);
   pgFaults++;
   //lruCount++;
   //printf("frameNum for LRU: %d\n",frameNum);
   
   } 
   
   
 // printf("we made it out");
  
  pageTable[pageNum].status = VALID;
  pageTable[pageNum].frameNum = frameNum;
  pageTable[pageNum].refCount = refCounter;
  refCounter++;
  
  long unsigned int newAddress = ((frameNum << 7) | offset);
  fwrite(&newAddress, sizeof(long unsigned int), 1, writeFile);
  
  //printf("0x%lx\n",newAddress);
  }

printf("number of page faults: %d\n", pgFaults);
//printf("LRU faults: %d\n", lruCount);
return 0;

}
