CC = gcc
COPS = -D_GNU_SOURCE -g

all: part1 part2

part1: part1.c
	$(CC) $(COPS) -o part1 part1.c
part2: part2.c pagetable.h pagetable.c phypages.h phypages.c
	$(CC) $(COPS) -o part2 part2.c phypages.h phypages.c pagetable.h pagetable.c 

clean:
	-rm part1 part2
