#include "SortedLists.h"

SortedLists * createSortedLists(){
	SortedLists *list = (SortedLists *)malloc(sizeof(SortedLists));
	list -> headNames = NULL;
	list -> headDOBs = NULL;
	return list;
}
int valDOB(DOB d){
	return (d.year*100 + d.month) * 100 + d.day;
}
int cmpDOB(DOB d1,DOB d2){
	return valDOB(d1) - valDOB(d2);
}
char * valName(Name n){
	char *name = (char * )malloc(100*sizeof(char));
	strcpy(name,"");
	if(n.last != NULL){
		strcat(name,n.last);
		strcat(name," ");
	}
	if(n.first != NULL){
		strcat(name,n.first);
	}
	return name;
}
int cmpName(Name n1,Name n2){
	return strcmp(valName(n1),valName(n2));
}
void insertSorted(struct SortedLists *aList, Name n, DOB d){
	SortedNode *nDobNode = (SortedNode *)malloc(sizeof(SortedNode));
	SortedNode *nNameNode = (SortedNode *)malloc(sizeof(SortedNode));
	nDobNode->name = n;
	nDobNode->dob = d;
	nDobNode->nextDOB = NULL;
	nDobNode->prevDOB = NULL;
	nNameNode->name = n;
	nNameNode->dob = d;
	nNameNode->nextName = NULL;
	nNameNode->prevName = NULL;

	SortedNode* current; 
    if (aList->headNames == NULL || cmpName(aList->headNames->name,nNameNode->name) >= 0) { 
        nNameNode->nextName = aList->headNames; 
        aList->headNames = nNameNode;
    } 
    else{ 
        current = aList->headNames; 
        while (current->nextName != NULL && cmpName(current->nextName->name,nNameNode->name) < 0) 
        { 
            current = current->nextName; 
        } 
        nNameNode->nextName = current->nextName; 
        nNameNode->prevName = current;
        current->nextName = nNameNode; 
    }
    if (aList->headDOBs == NULL || cmpDOB(aList->headDOBs->dob,nDobNode->dob) >= 0) { 
        nDobNode->nextDOB = aList->headDOBs; 
        aList->headDOBs = nDobNode;
    } 
    else{ 
        current = aList->headDOBs; 
        while (current->nextDOB !=NULL && cmpDOB(current->nextDOB->dob,nDobNode->dob) < 0) 
        { 
            current = current->nextDOB; 
        } 
        nDobNode->nextDOB = current->nextDOB; 
        nDobNode->prevDOB = current;
        current->nextDOB = nDobNode; 
    }
}
//PRE: aList has been created and the names list and DOB list are sorted
//insert a new element (n,d). The new element is inserted into aList so both the names
// list and DOB list remain sorted
//only one new SortedNode is created by each call to this function
void deleteSorted(struct SortedLists *aList, Name n, DOB d){
	SortedNode *tmp = aList->headDOBs;
	while(cmpName(aList->headDOBs->name,n) == 0 && cmpDOB(aList->headDOBs->dob,d) == 0){
		aList->headDOBs = aList->headDOBs->nextDOB;
		if(aList->headDOBs != NULL){
			aList->headDOBs->prevDOB = NULL;
		}
		else{
			break;
		}
	}
	while(tmp != NULL){
		if(cmpName(tmp->name,n) == 0 && cmpDOB(tmp->dob,d) == 0){
			if(tmp->prevDOB != NULL){
				tmp->prevDOB->nextDOB = tmp->nextDOB;
			}
			if(tmp->nextDOB != NULL){
				tmp->nextDOB->prevDOB = tmp->prevDOB;
			}
		}
		tmp = tmp->nextDOB;
	}
	while(cmpName(aList->headNames->name,n) == 0 && cmpDOB(aList->headNames->dob,d) == 0){
		aList->headNames = aList->headNames->nextName;
		if(aList->headNames != NULL){
			aList->headNames->prevName = NULL;
		}
		else{
			break;
		}
	}
	tmp = aList->headNames;
	while(tmp != NULL){
		if(cmpName(tmp->name,n) == 0 && cmpDOB(tmp->dob,d) == 0){
			if(tmp->prevName != NULL){
				tmp->prevName->nextName = tmp->nextName;
			}
			if(tmp->nextName != NULL){
				tmp->nextName->prevName = tmp->prevName;
			}
		}
		tmp = tmp->nextName;
	}
}
 //PRE: aList has been created and is sorted
 //remove all occurrences of elements that match (n,d)
DOB* findDOBs(struct SortedLists *aList, Name n){
	int i = 0;
	DOB *dobs = (DOB *)malloc(sizeof(DOB) * 100);
	SortedNode *tmp = aList->headNames;
	while(tmp != NULL){
		int r = cmpName(tmp->name,n);
		if(r > 0){
			break;
		}
		if(r == 0){
			dobs[i].month = tmp->dob.month;
			dobs[i].year = tmp->dob.year;
			dobs[i].day = tmp->dob.day;
			i++;
		}
		tmp = tmp->nextName;
	}
	dobs[i].month = 0;
	dobs[i].year = 0;
	dobs[i].day = 0;
	return dobs;
}
//PRE: aList has been created and is sorted
//return an array of DOBs for each name that matches n
//the last element in the array has a DOB with a values of year, month and day of 0, 0 and 0 respectively.
Name* findNames(struct SortedLists *aList, DOB d){
	int i = 0;
	Name *names = (Name *)malloc(sizeof(Name) * 100);
	SortedNode *tmp = aList->headDOBs;
	while(tmp != NULL){
		int r = cmpDOB(tmp->dob,d);
		if(r > 0){
			break;
		}
		if(r == 0){
			names[i].first = (char *)malloc(50);
			names[i].last = (char *)malloc(50);
			if(tmp->name.first != NULL){
				strcpy(names[i].first,tmp->name.first);
			}
			if(tmp->name.last != NULL){
				strcpy(names[i].last,tmp->name.last);
			}
			i++;
		}
		tmp = tmp->nextDOB;
	}

	names[i].first = (char *)malloc(50);
	strcpy(names[i].first,"");
	names[i].last = (char *)malloc(50);
	strcpy(names[i].last,"");
	return names;
}
//PRE: aList has been created and is sorted
//return an array of Names for each DOB that matches d
//the last element in the array has a Name with a values of first and last of NULL (\0), and NULL (\0) respectively.
void printOrderedNames(struct SortedLists *aList){
	SortedNode *tmp = aList->headNames;
	while(tmp != NULL){
		printf("%s %s %d %d %d\n", tmp->name.first ,tmp->name.last,tmp->dob.year,tmp->dob.month,tmp->dob.day );
		tmp = tmp->nextName;
	}
}
//PRE: aList has been created
//print the contents of the list (name and DOB) to standard out
//the elements in the list are printed one person per line
//the output should be sorted (ascending) by name
void printOrderedDOBs(struct SortedLists *aList){
	SortedNode *tmp = aList->headDOBs;
	while(tmp != NULL){
		printf("%s %s %d %d %d\n", tmp->name.first ,tmp->name.last,tmp->dob.year,tmp->dob.month,tmp->dob.day);
		tmp = tmp->nextDOB;
	}
}
//PRE: aList has been created
//print the contents of the list (name and DOB) to standard out
//the elements in the list printed one person per line
//the output should be sorted (descending) by age
void destroySortedList(struct SortedLists *aList){
	// SortedNode *tmp = aList->headDOBs;
	// while(tmp != NULL){
	// 	free(tmp);
	// 	tmp = tmp->nextDOB;
	// }
	// tmp = aList->headNames;
	// while(tmp != NULL){
	// 	free(tmp);
	// 	tmp = tmp->nextName;
	// }
	free(aList->headNames);
	free(aList->headDOBs);
}
 //PRE: aList has been created
 //free space created for aList
