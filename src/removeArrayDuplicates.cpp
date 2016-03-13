/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

int removeArrayDuplicates(int *Arr, int len)
{
	//check the initial conditions for Array i.e; array given should not be null and array length cannot be negative
	if (Arr != NULL && len > 0)
	{
		//find the duplicates and set their values to '-1'.
		for (int i = 0; i < len; i++)
		{
			int j = i + 1;
			while (j < len)
			{
				if (Arr[i] == Arr[j])
				{
					Arr[i] = -1;
				}
				j++;
			}
		}
		//when u find '-1' in array, shift the array elements forward.
		int index = 0;
		while (index < len)
		{
			if (Arr[index] == -1)
			{
				//shifting array elements forward and decreasing length by 1.
				for (int k = index; k < len - 1; k++)
				{
					Arr[k] = Arr[k + 1];
				}
				--len;
				index = -1; //as array values are changed,again array index starts checking from '0th' index
			}
			index++;
		}
		//print the final output array
		for (int i = 0; i < len; i++)
		{
			printf("%d ", Arr[i]);
		}
		return len;
	}
	return -1;
}