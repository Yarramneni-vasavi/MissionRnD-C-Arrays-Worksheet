/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

void MergeSort(struct student *students, int min, int max);
void Merge(struct student *students, int min, int mid, int max);
char *StringCopy(char *destination, char *source);

void * scoresDescendingSort(struct student *students, int len) 
{
	if (students != NULL && len > 0)
	{
		MergeSort(students, 0, len - 1);
		for (int i = 0; i < len; i++)
		{
			printf("%s - %d\n", students[i].name, students[i].score);
		}
	}
	return NULL;
}

void MergeSort(struct student *students, int min, int max)
{
	if (min < max)
	{
		int mid = (min + max) / 2;
		MergeSort(students, min, mid);		//in recursion, applying divide and conquer strategy
		MergeSort(students, mid + 1, max);
		Merge(students, min, mid, max);	//sorts and merges
	}
}

void Merge(struct student *students, int min, int mid, int max)
{
	struct student temp[4] = { {}, {}, {}, {} };
	int index, minimum = min, mid_minimum = mid + 1, k;
	for (index = minimum; minimum <= mid && mid_minimum <= max; index++)
	{
		if (students[minimum].score >= students[mid_minimum].score)
		{
			StringCopy(temp[index].name, students[minimum].name);
			temp[index].score = students[minimum].score;
			minimum++;
		}
		else
		{
			StringCopy(temp[index].name, students[mid_minimum].name);
			temp[index].score = students[mid_minimum].score;
			mid_minimum++;
		}
	}
	if (minimum > mid)
	{
		for (k = mid_minimum; k <= max; k++)
		{
			StringCopy(temp[index].name, students[k].name);
			temp[index].score = students[k].score;
			index++;
		}
	}
	else
	{
		for (k = minimum; k <= mid; k++)
		{
			StringCopy(temp[index].name, students[k].name);
			temp[index].score = students[k].score;
			index++;
		}
	}
	for (k = min; k <= max; k++)
	{
		StringCopy(students[k].name, temp[k].name);
		students[k].score = temp[k].score;
	}
}

char *StringCopy(char *destination, char *source)
{
	char *saved = destination;
	while (*source)
	{
		*destination++ = *source++;
	}
	*destination = 0;
	return saved;
}