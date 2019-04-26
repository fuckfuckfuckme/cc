struct SortedList {
	struct SortedNode *head;
};

struct SortedNode {
	int data;
	struct SortedNode *next;
};

struct SortedList * createSortedList();

void insertSorted(struct SortedList *aList, int x);

void removeSorted(struct SortedList *aList, int x);

int findSorted(struct SortedList *aList, int x);

void destroySortedList(struct SortedList *aList);

void printList(struct SortedList *aList);
