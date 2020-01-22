#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "misc.h"
#include "search.h"
#include "queue.h"

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
	int possibleMove = -1;

	srand((unsigned) time(&t));

	randArrayInitialization(*initialArray);
	//BFSSearch(*initialArray, *targetArray);
	//testNode(*initialArray, *targetArray);
	testQueue(*initialArray, *targetArray);

	/*
	for (i = 1; i < 5; i++)
	{
		possibleMove = validMovement(*initialArray, i);

		if (i == 1) //UP
		{
			if (possibleMove == 1)
			{
				printf("Possible UP\n");
			}
			else
			{
				printf("NOT possible UP\n");
			}
		}
		else if (i == 2) //RIGHT
		{
			if (possibleMove == 1)
			{
				printf("Possible RIGHT\n");
			}
			else
			{
				printf("NOT possible RIGHT\n");
			}
		}
		else if (i == 3) //DOWN
		{
			if (possibleMove == 1)
			{
				printf("Possible DOWN\n");
			}
			else
			{
				printf("NOT possible DOWN\n");
			}
		}
		else if (i == 4) //LEFT
		{
			if (possibleMove == 1)
			{
				printf("Possible LEFT\n");
			}
			else
			{
				printf("NOT possible LEFT\n");
			}
		}
	}
	*/
	
	return 0;
}