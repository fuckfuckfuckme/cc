CC=gcc
CFLAGS=-Wall -g

#
# List all of the binary programs you want to build here
# Separate each program with a single space
#
all: SortedLists.c

#
# Main shell program
#
sortedlists: SortedLists.c SortedLists.h 
	$(CC) -o SortedLists SortedLists.c $(CFLAGS)


#
# Cleanup the files that we have created
#
clean:
	$(RM) SortedLists *.o
	$(RM) -rf *.dSYM
