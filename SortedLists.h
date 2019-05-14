#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Implements double linked lists of names and dates of birth (DOB)
//One list is sorted in ascending order by name (last name the primary sort key and first name the
//secondary sort key).
//The second list is sorted in descending order by age (as determined by the DOB)
//There is only one SortedNode for each each data item (name and DOB)
//The node is part of two lists. The names list is traversed using nextNames and prevNames
//and the DOB list is traversed using nextDOB and prevDOB
typedef struct Name {
	char * first;
	char * last;
} Name;
typedef struct DOB {
	int year;
	int month;
	int day;
} DOB;

typedef struct SortedNode {
	Name name;
	DOB dob;
	struct SortedNode *nextName;
	struct SortedNode *nextDOB;
	struct SortedNode *prevName;
	struct SortedNode *prevDOB;
} SortedNode;

typedef struct SortedLists {
	SortedNode *headNames;
	SortedNode *headDOBs;
} SortedLists;

SortedLists * createSortedLists();
//return a new empty List
void insertSorted(struct SortedLists *aList, Name n, DOB d);
//PRE: aList has been created and the names list and DOB list are sorted
//insert a new element (n,d). The new element is inserted into aList so both the names
// list and DOB list remain sorted
//only one new SortedNode is created by each call to this function
 void deleteSorted(struct SortedLists *aList, Name n, DOB d);
 //PRE: aList has been created and is sorted
 //remove all occurrences of elements that match (n,d)
DOB* findDOBs(struct SortedLists *aList, Name n);
//PRE: aList has been created and is sorted
//return an array of DOBs for each name that matches n
//the last element in the array has a DOB with a values of year, month and day of 0, 0 and 0 respectively.
Name* findNames(struct SortedLists *aList, DOB d);
//PRE: aList has been created and is sorted
//return an array of Names for each DOB that matches d
//the last element in the array has a Name with a values of first and last of NULL (\0), and NULL (\0) respectively.
void printOrderedNames(struct SortedLists *aList);
//PRE: aList has been created
//print the contents of the list (name and DOB) to standard out
//the elements in the list are printed one person per line
//the output should be sorted (ascending) by name
void printOrderedDOBs(struct SortedLists *aList);
//PRE: aList has been created
//print the contents of the list (name and DOB) to standard out
//the elements in the list printed one person per line
//the output should be sorted (descending) by age
void destroySortedList(struct SortedLists *aList);
 //PRE: aList has been created
 //free space created for aList
