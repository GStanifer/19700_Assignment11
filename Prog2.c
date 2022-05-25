/*
Program:  Assignment 11, Prog 2
Made by:  Garrett Stanifer
Date:  5/3/2021
Using functions, find the largest, 2nd largest, sum of evens, and the count of the evens from a randomly generated array
*/

//Prototypes
void maximum(int a[], int numelements, int* maxPtr, int* secondPtr);
void evens(int a[], int numelements, int* sumPtr, int* countPtr);
void printResults(int arr[], int n, int sum, int count, int largest, int secondLargest);

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  
#include <time.h>

int main()
{
	int i, largest, secondLargest, sum, count;
	int arr[20];
	srand(time(NULL));

	for (i = 0; i < 20; i++)
	{
		arr[i] = rand() % 25 + 1;
	}

	maximum(arr, 20, &largest, &secondLargest);
	evens(arr, 20, &sum, &count);
	printResults(arr, 20, sum, count, largest, secondLargest);


	return 0;
}
//Finds the largest and 2nd largest numbers within the array generated
void maximum(int arr[], int numElements, int* largestPtr, int* secondLargestPtr)
{
	int i;
	*largestPtr = -99999;
	*secondLargestPtr = -99999;
	for (i = 0; i < numElements; i++)
	{
		if (arr[i] > *largestPtr)
		{
			*secondLargestPtr = *largestPtr;
			*largestPtr = arr[i];
		}
		else if (arr[i] > secondLargestPtr)
			*secondLargestPtr = arr[i];
	}
}
//Finds the number of even numbers in the generated array and takes the sum
void evens(int arr[], int numelements, int* sumPtr, int* countPtr)
{
	int i;
	*sumPtr = 0;
	*countPtr = 0;
	for (i = 0; i < numelements; i++)
	{
		if (arr[i] % 2 == 0)  //If the generated number is allocated as an even
		{
			*sumPtr += arr[i];
			*countPtr += 1;
		}
	}
}
//Prints the results from the previous funtions 
void printResults(int arr[], int numElements, int sum, int count, int largest, int secondLargest)
{
	int i;
	printf("The random numbers generated are:  \n");
	for (i = 0; i < numElements; i++)
	{
		if (i == 10)
			printf("\n");
		printf("%d ", arr[i]);
	}

	printf("\n\n");
	printf("The largest value is:  %d\n", largest);
	printf("The second largest value is:  %d\n", secondLargest);  
	printf("The sum of the evens is:  %d\n", sum);
	printf("The count of the evens is:  %d\n", count);
}
