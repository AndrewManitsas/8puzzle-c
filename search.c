#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//movement definitions
const int UP = 1;
const int RIGHT = 2;
const int DOWN = 3;
const int LEFT = 4;

void BFSSearch(int *IA, int *TA)
{
	int i = 0, j = 0;
	int initialArray[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
	int targetArray[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			initialArray[i][j] = *IA;
			targetArray[i][j] = *TA;
			*IA++;
			*TA++;
		}   
	}

	printf("BFS Search function called\n");
	
	printf("Initialized array:\n------------\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf(" %d |", initialArray[i][j]);
		}
		printf("\n------------\n");
	}

	printf("\nTarget array:\n------------\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf(" %d |", targetArray[i][j]);
		}
		printf("\n------------\n");
	}
}

void AstarSearch(int *IA, int *TA)
{
	printf("A* Search function called\n");
}