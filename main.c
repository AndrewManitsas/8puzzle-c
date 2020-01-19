#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "misc.h"
#include "search.h"

unsigned int nodesExpanded = 0;
unsigned int nodesGenerated = 0;
unsigned int solutionLength = 0;
double runtime = 0; //in milliseconds

int main ()
{
	time_t t;
	int i = 0, j = 0;
	int initialArray[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
	int targetArray[3][3] = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};

	srand((unsigned) time(&t));

	randArrayInitialization(*initialArray);

	//Check the array
	/*
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
	*/

	BFSSearch(*initialArray, *targetArray);

	return 0;
}