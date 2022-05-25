/*
Program:  Assignment 11, Prog 1
Made by:  Garrett Stanifer
Date:  5/3/2021
Determine change from a $20 bill used to purchase an item
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	double n;
	int i, change;
	int coins[5] = { 100, 25, 10, 5, 1 };
	int count[5];


	printf("Enter the cost of the item:  ");  //User enters price of item
	scanf_s("%lf", &n);
	
	 change = (20 - n) * 100;
	printf("\nAmount of change left:  %.2lf\n\n", change / 100.0); //Prints amount of change to 2 decimal places

	printf("Dollars\tQuarters Dimes\tNickels\tPennies\n");  //Top labels for amount of each coin

	for (i = 0; i < 5; i++) 
	{
		count[i] = change / coins[i];
		change = change % coins[i];  //Change is equal to the modulus of change over coins
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d\t", count[i]);  //Prints the number of each coin
	}

	return 0;
}

