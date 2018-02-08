//Austin Emery
//Algorithms
//hm3
//10/3/2017

//This is the altered bubble sort.

//To compile: gcc modifiedBubble.c -o test
//To run: ./test

#include <stdio.h>

void modifiedBubble(char *, int);

void printArray(char *, int);

int main()
{
	int arrayLen = 12;
	char array[] = {'E', 'A', 'S', 'Y', 'Q', 'U', 'E', 'S', 'T', 'I', 'O', 'N'};

	modifiedBubble(array, arrayLen);
}

void modifiedBubble(char *array, int arrayLen)
{
	int didSwap = 1;

	int i, j, temp;

	int leftBumper = 0;
	int rightBumper = arrayLen - 1;

	int numbCompares = 0, passNumb = 1;

	printf("Unsorted Array: ");
	printArray(array, arrayLen);
	printf("\n");

	while (1)
	{
		didSwap = 0;

		for (i = leftBumper; i < rightBumper; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				didSwap = 1;
			}
			numbCompares++;
		}

		rightBumper--;
		printf("Left->Right pass #%d:\t", passNumb++);
		printArray(array, arrayLen);
		
		for (j = rightBumper; j > leftBumper; j--)
		{
			if (array[j] < array[j - 1])
			{
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
			numbCompares++;
		}

		leftBumper++;
		printf("Right->Left pass #%d:\t", passNumb++);
		printArray(array, arrayLen);

		if(didSwap == 0)
		{
			break;
		}
	}

	printf("\nSorted Array: ");
	printArray(array, arrayLen);

	printf("\nNumber of Compares: %d\n", numbCompares);	
}

void printArray(char *array, int arrayLen)
{
	int i = 0;

	for (i = 0; i < arrayLen; i++)
	{
		printf("%c ", array[i]);
	}
	printf("\n");
}