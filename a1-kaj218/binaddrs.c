#include <stdio.h>
#include <stdint.h>

/*
 Cody Mangold - kaj218
OS fall 2023
Assignment 1
	
*/
void printAddress(uint64_t line, int lineCount)

{

printf("Address %4d: 0x%016lx -> 0x%014lx : 0x%02lx\n", lineCount, line, (line >> 8), (line & 0xFF));

}


int main( int argc, char* argv[])

{

	if(argc < 2)
		{
			fprintf(stderr, "Invalid argc count, %s", argv[0]);
			return 1; 
		}
	int count;
	FILE* datafile;
	size_t line_Amount;
	uint64_t buffer;
	for(count = 1 ;count < argc; count++)
	{

		int addressCounter = 1;
		int loopCount;
		if((datafile = fopen(argv[count],"rb")) == NULL)
		{
			fprintf(stderr,"ERROR: unable to open datafile %s",argv[count]);
			return -1;
		}

		while((line_Amount = fread(&buffer, sizeof(uint64_t), 1L, datafile)) == 1) {
			printAddress(buffer, addressCounter);
			++addressCounter;
		}
		if(line_Amount == 0 && !feof(datafile)) {
			fprintf(stderr, "ERROR: failed to next read 8 byte value, quitting...\n");
			return -1;
		}
		fclose(datafile);			
	}
	return 0;
}
