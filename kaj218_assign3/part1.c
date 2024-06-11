#include <stdio.h>
#include <stdint.h>

/* 
Cody Mangold - kaj218
CS-3733-003
Assignment 3: Paging
*/



int main(int argc, char* argv[])
{

 FILE* dataFile;
 FILE* writeFile;
 size_t lineHolder;
 uint64_t buffer;
 uint64_t pageNum;
 uint64_t offset;
 uint64_t frameNum;
 int pageTable[] = {2,4,1,7,3,5,6};
if(argc < 3)
{
printf("Error not enough parameters, Exiting!\n");
return -1;
}

 if((dataFile = fopen(argv[1],"rb")) == NULL )
	{
	fprintf(stderr, "Error opening file: %s!\n",argv[1]);
	return -1;

	}

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
	frameNum = pageTable[pageNum];
//	printf("Frame number: %d\n", frameNum);
	//printf("virtual address: 0x%lx -->  physical address conversion: 0x%lx\n" , buffer, (frameNum << 7 | offset));
 uint64_t newAddress = (frameNum << 7 | offset);
 //printf("virtual address: 0x%lx -->  physical address conversion: 0x%lx\n" , buffer, newAddress);
 fwrite(&newAddress, sizeof(uint64_t), 1, writeFile);
	}




   fclose(dataFile);
   fclose(writeFile);


return 0;
}
