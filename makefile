CC=gcc
CFLAGS=-I.
DEPS = SortedLists.h
OBJ = TestDrivers.o SortedLists.o
%.o: %.c $(DEPS)
        $(CC) -c -o $@ $< $(CFLAGS)

sortedlistmake: $(OBJ)
        $(CC) -o $@ $^ $(CFLAGS)
