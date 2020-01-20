#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declared in main.c
extern unsigned int nodesGenerated;
extern unsigned int nodesGenerated;
extern unsigned int solutionLength;
extern double runtime; //in milliseconds

//movement definitions
const int UP = 1;
const int RIGHT = 2;
const int DOWN = 3;
const int LEFT = 4;

struct Node
{
	int *state;
	struct Node *parent;
	int action;
	int cost;
	int depth;
};

//Used only for debugging and testing
void testNode(int *IA, int *TA)
{
	struct Node child, father, *fatherPointer;

	child.state = TA;
	child.action = 1;
	child.cost = 1;
	child.depth = 1;
	child.parent = &father;

	father.state = IA;
	father.action = 5;
	father.cost = 0;
	father.depth = 0;
	father.parent = NULL;

	fatherPointer = &father;
	
	printf("Child Action: %d\nChild Cost: %d\nChild Depth: %d\nChild Parent: %d\n\n", child.action, child.cost, child.depth, child.parent);
	printf("Father Action: %d\nFather Cost: %d\nFather Depth: %d\nFather Parent: %d\n\n", fatherPointer->action, fatherPointer->cost, fatherPointer->depth, fatherPointer->parent);
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