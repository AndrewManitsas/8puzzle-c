#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declared in main.c
extern unsigned int nodesGenerated;
extern unsigned int nodesGenerated;
extern unsigned int solutionLength;
extern double runtime; //in milliseconds

int searchFrontierHead = 0, searchFrontierTail = 0;

typedef struct TreeNode TreeNode;

struct TreeNode
{
	int *state;
	TreeNode *parentNode;
	int action;
	int pathCost;
	int pathDepth;
	//Maybe a pointer list with the children?	
};

void initializeSearchFrontierQueue(int *head, int *tail)
{
	*head = *tail = 0;
}

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