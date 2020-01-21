#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

struct QueueElement
{
	struct Node *currentElement;
	struct QueueElement *next;
};

struct Queue
{
	struct QueueElement *front;
	struct QueueElement *rear;
};

struct Queue *createQueue()
{
	struct Queue *q = (struct Queue*) malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}

void addToQueue(struct Queue *Qpointer, struct Node *NodeToAdd)
{
	struct QueueElement *temp = (struct QueueElement*) malloc(sizeof(struct QueueElement));
	temp->currentElement = NodeToAdd;
	temp->next = NULL;

	//If queue is empty
	if ((Qpointer->front == NULL) && (Qpointer->rear == NULL))
	{
		Qpointer->front = Qpointer->rear = temp;
		return;
	}

	//If the queue is not empty
	Qpointer->rear->next = temp;
	Qpointer->rear = temp;
}

struct Node *removeFromQueue(struct Queue *Qpointer)
{
	//IF Queue is empty
	if (Qpointer->front == NULL)
	{
		return NULL;
	}

	//IF Queue is not empty

	//Store previous front and move front 1 place ahead
	struct QueueElement *temp = Qpointer->front;
	free(temp);
	Qpointer->front = Qpointer->front->next;

	//If front = null then change rear = null
	if (Qpointer->front == NULL)
	{
		Qpointer->rear = NULL;
	}

	return temp->currentElement;
}

int validMovement(int *state, int movement)
{
	//See the movement definitions above
	//Returns 1 for valid move, 0 for invalid move

	int array[3][3], i = 0, j = 0;
	int possibleMove = -1; //1 for valid move, 0 for invalid move
	int gapRow = -1, gapCol = -1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			array[i][j] = *state;
			*state++;
			//printf("Cell %d %d: %d\n", i, j, array[i][j]);

			if (array[i][j] == 0)
			{
				gapRow = i;
				gapCol = j;
			}
		}
	}

	if (movement == UP)
	{
		if ((gapRow - 1) > -1)
		{
			possibleMove = 1;
		}
		else
		{
			possibleMove = 0;
		}
	}
	else if (movement == RIGHT)
	{
		if ((gapCol + 1) < 3)
		{
			possibleMove = 1;
		}
		else
		{
			possibleMove = 0;
		}
	}
	else if (movement == DOWN)
	{
		if ((gapRow + 1) < 3)
		{
			possibleMove = 1;
		}
		else
		{
			possibleMove = 0;
		}
	}
	else if (movement == LEFT)
	{
		if ((gapCol - 1) > -1)
		{
			possibleMove = 1;
		}
		else
		{
			possibleMove = 0;
		}
	}

	return possibleMove;
}

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