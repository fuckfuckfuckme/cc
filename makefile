CC=gcc
CFLAGS=-Wall -g

#
# List all of the binary programs you want to build here
# Separate each program with a single space
#
all: sortedlists

#
# Main shell program
#
sortedlists: sortedlists.c sortedlists.h 
	$(CC) -o sortedlists $(CFLAGS) sortedlists.c


#
# Cleanup the files that we have created
#
clean:
	$(RM) sortedlists *.o
	$(RM) -rf *.dSYM
