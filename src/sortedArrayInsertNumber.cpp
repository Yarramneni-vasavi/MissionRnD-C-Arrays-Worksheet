/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int trace;
	if (Arr != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (num > Arr[0] && num < Arr[len - 1] && num > Arr[i] && num < Arr[i + 1])
			{
				trace = i + 1;
			}
			else if (num < Arr[0])
			{
				trace = 0;
			}
			else if (num > Arr[len - 1])
			{
				trace = len;
			}
			else if (num == Arr[i])
			{
				trace = i + 1;
			}
		}
		for (int i = len; i > trace; i--)
		{
			Arr[i] = Arr[i - 1];
		}
		Arr[trace] = num;
		return Arr;
	}
	return NULL;
}