#include "SortedLists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMLISTS 3

//Used to hold data read from files so it can be resued
typedef struct Data {
    Name name;
    DOB dob;
} Data;



//arrays and lists hold data from input files; columns in data (50) is big enough for the files I am using
//This is not very efficent but it enables me to reuse data from the files
Data data[NUMLISTS][60];
int numCols[NUMLISTS]; //number of columns used in each row
SortedLists * list[NUMLISTS];
FILE * dataFiles[NUMLISTS];

void initNameSpace() {
    //assumes no first name or last name is longer 49 characters;
    int i,j;
    for (i = 0; i < NUMLISTS; i++) {
        for (j = 0; j < 60; j++) {
            data[i][j].name.first = (char *) malloc(50*sizeof(char));
            data[i][j].name.last = (char *) malloc(50*sizeof(char));
        }
    }
}

void readFileOneName(int i) {
    int j = 0;
    char * format;
    while ((fscanf(dataFiles[i], "%s%d%d%d", data[i][j].name.last,
                   &data[i][j].dob.year, &data[i][j].dob.month, &data[i][j].dob.day )) != EOF) {
        strcpy(data[i][j].name.first, " ");
        j++;
    }
    numCols[i] = j;
}

void readFileTwoName(int i) {
    int j = 0;
    char * format;
    while ((fscanf(dataFiles[i], "%s%s%d%d%d", data[i][j].name.first, data[i][j].name.last,
                   &data[i][j].dob.year, &data[i][j].dob.month, &data[i][j].dob.day )) != EOF) {
        j++;
    }
    numCols[i] = j;
}

void readData() {
    int i;
    dataFiles[0] = fopen("oneName.txt", "r");
    dataFiles[1] = fopen("twoNames1.txt", "r");
    dataFiles[2] = fopen("twoNames2.txt", "r");
    
    readFileOneName(0);
    for (i = 1; i < NUMLISTS; i++) {
        readFileTwoName(i);
    }
}

void loadListInOrder(int i) {  //uses the data array in order
    int j;
    //printf("Insert into list %d\n", i);
    for (j = 0; j < numCols[i]; j++) {
        //printf("%s %s %d %d %d\n", data[i][j].name.first, data[i][j].name.last, data[i][j].dob.year, data[i][j].dob.month, data[i][j].dob.day);
        insertSorted(list[i], data[i][j].name, data[i][j].dob);
    }
}

void loadListsInOrder() {
    int i;
    for (i = 0; i < NUMLISTS; i++) {
        list[i] = createSortedLists();
        loadListInOrder(i);
    }
}

void loadListInReverse(int i) {  //uses the data array in order
    int j;
    //printf("Insert into list %d\n", i);
    for (j = numCols[i]-1; j >= 0; j--) {
        //printf("%s %s %d %d %d\n", data[i][j].name.first, data[i][j].name.last, data[i][j].dob.year, data[i][j].dob.month, data[i][j].dob.day);
        insertSorted(list[i], data[i][j].name, data[i][j].dob);
    }
}

void loadListsInReverse() {
    int i;
    for (i = 0; i < NUMLISTS; i++) {
        loadListInReverse(i);
    }
}

void printListsByName() {
    int i;
    for (i = 0; i < NUMLISTS; i++) {
        printf("Print list %d by Name\n\n", i);
        printOrderedNames(list[i]);
        printf("\n\n");
    }
}

void printListsByDOB() {
    int i;
    for (i = 0; i < NUMLISTS; i++) {
        printf("Print list %d by DOB\n\n", i);
        printOrderedDOBs(list[i]);
        printf("\n\n");
    }
}

void deleteAllOfOne(int i) {  //uses the data array in order
    int j;
    //printf("Insert into list %d\n", i);
    for (j = 0; j < numCols[i]; j++) {
        //printf("%s %s %d %d %d\n", data[i][j].name.first, data[i][j].name.last, data[i][j].dob.year, data[i][j].dob.month, data[i][j].dob.day);
        deleteSorted(list[i], data[i][j].name, data[i][j].dob);
    }
}

void deleteAll() {
    int i;
    for (i = 0; i < NUMLISTS; i++) {
        deleteAllOfOne(i);
    }
}

void deleteHalfOfOne(int i) {  //uses the data array in order
    int j;
    //printf("Insert into list %d\n", i);
    for (j = numCols[i]/2; j < numCols[i]; j++) {
        //printf("%s %s %d %d %d\n", data[i][j].name.first, data[i][j].name.last, data[i][j].dob.year, data[i][j].dob.month, data[i][j].dob.day);
        deleteSorted(list[i], data[i][j].name, data[i][j].dob);
    }
}

void deleteHalf() {
    int i;
    for (i = 0; i < NUMLISTS; i++) {
        deleteHalfOfOne(i);
    }
}

void printDOBs(Name n, DOB d[]) {
    int i = 0;;
    printf("Name: %s %s DOBs\n", n.first, n.last);
    while (!(d[i].year == 0 && d[i].month == 0 && d[i].day == 0)) {
        printf("%d %d %d\n",d[i].year, d[i].month,d[i].day );
        i++;
    }
    
}

void findByNamesOneList(int i) {  //uses the data array in order
    int j;
    DOB * d;
    //printf("Insert into list %d\n", i);
    for (j = 0; j < numCols[i]; j++) {
        //printf("%s %s %d %d %d\n", data[i][j].name.first, data[i][j].name.last, data[i][j].dob.year, data[i][j].dob.month, data[i][j].dob.day);
        d = findDOBs(list[i], data[i][j].name);
        printDOBs(data[i][j].name, d);
    }
}

void findByNames() {
    int i;
    for (i = 0; i < NUMLISTS; i++) {
        findByNamesOneList(i);
    }
}

void printNames(DOB d, Name n[]) {
    int i = 0;
    printf("DOB: %d %d %d names\n", d.year, d.month, d.day);
    while (strcmp(n[i].first, "") != 0 && strcmp(n[i].last, "") != 0) {
        printf("%s %s\n",n[i].first, n[i].last);
        i++;
    }
    
}

void findByDOBOneList(int i) {  //uses the data array in order
    int j;
    Name * n;
    //printf("Insert into list %d\n", i);
    for (j = 0; j < numCols[i]; j++) {
        //printf("%s %s %d %d %d\n", data[i][j].name.first, data[i][j].name.last, data[i][j].dob.year, data[i][j].dob.month, data[i][j].dob.day);
        n = findNames(list[i], data[i][j].dob);
        printNames(data[i][j].dob, n);
    }
}

void findByDOBs() {
    int i;
    for (i = 0; i < NUMLISTS; i++) {
        findByDOBOneList(i);
    }
}

void destroyAll() {
    int i;
    for (i = 0; i < NUMLISTS; i++) {
        destroySortedList(list[i]);
    }
}
int main(int argc, char * argv[]) {
    

    initNameSpace();
    readData();
    printf("Start tests\n\n");
    loadListsInOrder();
    loadListsInReverse();
    printf("After inserts\n\n");
    printListsByName();
    printf("After print by names\n\n");
    printListsByDOB();
    printf("After print by DOB\n\n");
    deleteAll();
    
    printf("After deletes\n\n");
    printListsByName();
    printf("After print by names\n\n");
    printListsByDOB();
    printf("After print by DOB\n\n");
    
    printf("Start second inserts\n\n");
    loadListsInOrder();
    printf("After in order inserts in order\n\n");
    loadListsInReverse();
    printf("After reverse inserts in order\n\n");
    printListsByName();
    printf("After print by names\n\n");
    printListsByDOB();
    printf("After print by DOB\n\n");
    
    findByNames();
    printf("After find by names\n\n");
    findByDOBs();
    printf("After find by DOBs\n\n");
    
    deleteHalf();
    
    printf("After delete half\n\n");
    printListsByName();
    printf("After print by names\n\n");
    printListsByDOB();
    printf("After print by DOB\n\n");
    
    
    destroyAll();
    exit(0);

}
