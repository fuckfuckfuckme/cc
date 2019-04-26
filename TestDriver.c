#include <stdio.h>
#include <stdlib.h>
#include "SortedList.h"

int main(int argc, const char * argv[]){
	printf("Running\n");

	struct SortedList *x;
	x = createSortedList();
	insertSorted(x,11);
	insertSorted(x,7);
	insertSorted(x,2);
	insertSorted(x,1);
	insertSorted(x,19);
	insertSorted(x,4);

	printList(x);

	int i = findSorted(x,11);
	int j = findSorted(x,3);

	printf("11: %d\n", i);
	printf("3: %d\n", j);

	removeSorted(x,11);
	removeSorted(x,7);
	insertSorted(x,6);

	printList(x);

	i = findSorted(x,11);
	j = findSorted(x,3);

	printf("11: %d\n", i);
	printf("3: %d\n", j);

	destroySortedList(x);

	printf("Complete\n");
}
