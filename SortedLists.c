#include "sortedlists.h"
#include<string.h>
Name narr[1000];
DOB darr[1000];


int isage(DOB d1, DOB d2)
{
   if (d1.year > d2.year)
       return 1;
   if (d1.year == d2.year && d1.month > d2.month)
       return 1;
   if (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day)
       return 1;
   return 0;

}
void insertSorted(struct SortedLists *aList, Name n, DOB d)
{
   SortedNode *temp = (SortedNode*)malloc(sizeof(SortedNode));
   temp->dob = d;
   temp->name = n;

   SortedNode *headname = aList->headNames;
   SortedNode *headdob = aList->headDOBs;

   if (headname == NULL)
   {
       aList->headNames = temp;
   }
   else
   {
       while (headname)
       {
           if ((strcmp(headname->name.last, n.last) < 0 ) ||
               (strcmp(headname->name.last, n.last) == 0 && strcmp(headname->name.first, n.first) <0))
           {
          
               if (headname == aList->headNames)
               {
                   aList->headNames = temp;
                   temp->nextName = aList->headNames;
               }
               else
               {
                   temp->nextName = headname->nextName;
                   temp->prevName = headname;
                   headname->nextName = temp;
               }
           }
           headname = headname->nextName;
       }
   }
   if (headdob == NULL)
   {
       aList->headDOBs = temp;
   }
   else
   {
       while (headdob)
       {
           if (isage(headdob->dob, d))
           {
               if (headdob == aList->headDOBs)
               {
                   aList->headDOBs = temp;
                   temp->nextDOB = aList->headDOBs;
               }
               else
               {
                   temp->nextDOB = headname->nextDOB;
                   temp->prevDOB = headname;
                   headdob->nextDOB = temp;
               }
           }
           headname = headname->nextName;
       }
   }
}
void deleteSorted(struct SortedLists *aList, Name n, DOB d)

{
   SortedNode *headname = aList->headNames;

   while (headname)
   {
       if (headname->dob.year == d.year && headname->dob.month == d.month && headname->dob.day == d.day &&
           strcmp(headname->name.first, n.first) == 0 && strcmp(headname->name.last, n.last) == 0)

       {
           if (headname->nextName)
           headname->nextName->prevName = headname->prevName;
           if(headname->prevName)
           headname->prevName->nextName = headname->nextName;

           if(headname->nextDOB)
           headname->nextDOB->prevDOB = headname->prevDOB;
      
           if(headname->prevDOB)
           headname->prevDOB->nextDOB = headname->nextDOB;


       }
       headname = headname->nextName;
   }

}
DOB* findDOBs(struct SortedLists *aList, Name n)
{
   int i = 0;


   SortedNode *headdob = aList->headDOBs;

   while (headdob)
   {
       if (strcmp(headdob->name.first, n.first) == 0 && strcmp(headdob->name.last, n.last) == 0)
           darr[i++] = headdob->dob;
       headdob = headdob->nextDOB;
   }
   DOB d;
   d.day = 0;
   d.month = 0;
   d.year = 0;
   darr[i] = d;
   return darr;
}
Name* findNames(struct SortedLists *aList, DOB d)
{
   SortedNode *headname = aList->headNames;

   int i = 0;


   while (headname)
   {
       if (headname->dob.year == d.year && headname->dob.month == d.month && headname->dob.day == d.day)
           narr[i++] = headname->name;
       headname = headname->nextName;
   }
   Name n;
   n.first = '\0';
   n.last = '\0';
   narr[i] = n;
   return narr;
}
void printOrderedNames(struct SortedLists *aList)
{

   SortedNode *headname = aList->headNames;

   while (headname)
   {
       printf("Name = %s %s and DOB = %d %d %d", headname->name.first, headname->name.last,
           headname->dob.day, headname->dob.month, headname->dob.year);
       headname = headname->nextName;
   }
}
void printOrderedDOBs(struct SortedLists *aList)

{
  
   SortedNode *headdob = aList->headDOBs;

   while (headdob)
   {
       printf("Name = %s %s and DOB = %d %d %d", headdob->name.first, headdob->name.last,
           headdob->dob.day, headdob->dob.month, headdob->dob.year);
       headdob = headdob->nextDOB;
   }

}
void destroySortedList(struct SortedLists *aList)
{
   SortedNode *headname = aList->headNames;
   SortedNode *next;

   while (headname)
   {
       next = headname->nextName;
       free(headname);
       headname = next;
   }

}
