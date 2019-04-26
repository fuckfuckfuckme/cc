#include <stdio.h>

void
insertionSort (int nums[], int size)
{
int i, j, var;
for (i = 1; i < size; i++)
{
var = nums[i];
j = i - 1;


while (j >= 0 && nums[j] > var)
{
  nums[j + 1] = nums[j];
  j = j - 1;
}
nums[j + 1] = var;
}
}

int
binarySearch (int nums[], int size, int searchVal)
{
int var = 0, var1 = size - 1;

while (var <= var1)
{
int m = var + (var1 - var) / 2;

if (nums[m] == searchVal)
return m;

if (nums[m] < searchVal)
var = m + 1;
else
var1 = m - 1;
}
return -1;
}

int
main ()
{
int num;
printf ("Enter the number of elements (between 1 and 50) in the array: \n");
scanf ("%d", &num);
int i, nums[num];
printf ("Enter %d positive integers: \n", num);
for (i = 0; i < num; i++)
{
scanf ("%d", &nums[i]);
}
int var = 0;
insertionSort (nums, num);
printf ("Enter a positive integer or -1 to quit: \n");
scanf ("%d", &var);
while(var != -1)
{
int ind = binarySearch (nums, num, var);
if (ind > 0)
{
  printf ("Found\n");
}
else
{
  printf ("Not Found\n");
}
printf ("Enter a positive integer or -1 to quit: \n");
scanf ("%d", &var);
}
return 0;
}
