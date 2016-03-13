/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

void students_Merge(struct student *students, int, int, int);
void students_MergeSort(struct student *students, int, int);

struct student ** topKStudents(struct student *students, int len, int K) 
{
	if (students != NULL && len > 0 && K>0)
	{
		struct student **top_K_students = NULL;
		top_K_students = (student**)malloc(K*sizeof(student));

		if (K < len)
		{
			students_MergeSort(students, 0, len - 1);
		}
		else if (K >= len)
		{
			K = len;
		}

		//top 'k' students are put into top_K_students array
		for (int i = 0; i < K; i++)
		{
			top_K_students[i] = (struct student*)malloc(sizeof(struct student));
			top_K_students[i] = &students[i];
		}

		return top_K_students;
	}
	return NULL;
}

void students_MergeSort(struct student *students, int min, int max)
{
	if (min < max)
	{
		int mid = (min + max) / 2;
		//sort left part of array
		students_MergeSort(students, min, mid);
		//sort right part of array
		students_MergeSort(students, mid + 1, max);
		//merge two sorted arrays(i.e; left and right parts)
		students_Merge(students, min, mid, max);	
	}
}

void students_Merge(struct student *students, int min, int mid, int max)
{
	//temporary array to store sorted array
	struct student *temp = (student *)malloc(10 * sizeof(student));
	int index, minimum = min, mid_minimum = mid + 1, k;
	for (index = minimum; minimum <= mid && mid_minimum <= max; index++)
	{
		if (students[minimum].score >= students[mid_minimum].score)
		{
			temp[index].name = students[minimum].name;
			temp[index].score = students[minimum].score;
			minimum++;
		}
		else
		{
			temp[index].name = students[mid_minimum].name;
			temp[index].score = students[mid_minimum].score;
			mid_minimum++;
		}
	}
	if (minimum > mid)
	{
		for (k = mid_minimum; k <= max; k++)
		{
			temp[index].name = students[k].name;
			temp[index].score = students[k].score;
			index++;
		}
	}
	else
	{
		for (k = minimum; k <= mid; k++)
		{
			temp[index].name = students[k].name;
			temp[index].score = students[k].score;
			index++;
		}
	}
	//copying temporary array to students array
	for (k = min; k <= max; k++)
	{
		students[k].name = temp[k].name;
		students[k].score = temp[k].score;
	}
}