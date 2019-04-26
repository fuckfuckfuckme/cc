/*
 * 
 * a C program that implements insertionSort,
 * binarySearch and main. 
 *
 * @author Travis Waldvogel
 *
 */
#include <stdio.h>
void
insertionSort (int nums[], int size)
{
	int i, key, j;
	for (i = 1; i < size; i++)
		{
			key = nums[i];
			j = i - 1;

/* Move elements of arr[0..i-1], that are
greater than key, to one position ahead
of their current position */
			while (j >= 0 && nums[j] > key)
	{
	  nums[j + 1] = nums[j];
	  j = j - 1;
	}
			nums[j + 1] = key;
		}
}

int
binarySearch (int nums[], int size, int searchVal)
{
	int l = 0, r = size - 1;

	while (l <= r)
		{
			int m = l + (r - l) / 2;

// Check if x is present at mid
			if (nums[m] == searchVal)
	return m;

// If x greater, ignore left half
			if (nums[m] < searchVal)
	l = m + 1;

// If x is smaller, ignore right half
			else
	r = m - 1;
		}

// if we reach here, then element was
// not present
	return -1;
}

int
main ()
{
	int n;
	printf ("Enter the number of elements (between 1 and 50) in the array: \n");
	scanf ("%d", &n);
	int i, nums[n];
	printf ("Enter %d positive integers: \n", n);
	for (i = 0; i < n; i++)
		{
			scanf ("%d", &nums[i]);
		}
	int x = 0;
	insertionSort (nums, n);
	printf ("Enter a positive integer or -1 to quit: \n");
	scanf ("%d", &x);
	do
		{
			int ind = binarySearch (nums, n, x);
			if (ind > 0)
	{
	  printf ("Found\n");
	}
			else
	{
	  printf ("Not Found\n");

	}
			printf ("Enter a positive integer or -1 to quit: \n");
			scanf ("%d", &x);
		}
	while (x != -1);

	return 0;
}
