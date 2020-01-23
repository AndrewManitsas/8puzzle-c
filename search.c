#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

extern unsigned int nodesExpanded;
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

struct Node *newNode(int *state, struct Node *parent, int action, int cost, int depth)
{
	struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
	temp->state = state;
	temp->parent = parent;
	temp->action = action;
	temp->cost = cost;
	temp->depth = depth;
	return temp;
}

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

//Used only for debugging and testing
void testQueue(int *IA, int *TA)
{
	printf("Called test queue function\n");
	
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

	struct Queue *q = createQueue();
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->state = IA;
	newNode->action = UP;
	newNode->cost = 1;
	newNode->depth = 1;
	newNode->parent = NULL;
	addToQueue(q, newNode);

	struct Node *newNode2 = (struct Node*) malloc(sizeof(struct Node));
	newNode2->state = IA;
	newNode2->action = RIGHT;
	newNode2->cost = 2;
	newNode2->depth = 2;
	newNode2->parent = NULL;
	addToQueue(q, newNode2);

	struct Node *newNode3 = (struct Node*) malloc(sizeof(struct Node));
	newNode3->state = IA;
	newNode3->action = DOWN;
	newNode3->cost = 3;
	newNode3->depth = 3;
	newNode3->parent = NULL;
	addToQueue(q, newNode3);

	struct Node *newNode4 = (struct Node*) malloc(sizeof(struct Node));
	newNode4->state = IA;
	newNode4->action = LEFT;
	newNode4->cost = 4;
	newNode4->depth = 4;
	newNode4->parent = NULL;
	addToQueue(q, newNode4);

	for (i = 1; i < 5; i++)
	{
		printf("Queue Position %d | Action %d | Cost %d | Depth %d | Parent %d\n", i, q->front->currentElement->action, q->front->currentElement->cost, q->front->currentElement->depth, q->front->currentElement->parent);
		q->front = q->front->next;
	}
}

int arrayMatching(int *IA, int *TA)
{
	int i = 0, j = 0;
	int initialArray[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
	int targetArray[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
	int matchingTable[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			initialArray[i][j] = *IA;
			targetArray[i][j] = *TA;
			*IA++;
			*TA++;
			matchingTable[i][j] = initialArray[i][j] - targetArray[i][j];
		}
	}

	if (memcmp(initialArray, targetArray, sizeof(initialArray)) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void BFSSearch(int *IA, int *TA)
{
	int i = 0, j = 0;
	int initialArray[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
	int targetArray[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
	struct Queue *SearchFrontier = createQueue();
	struct Queue *VisitedList = createQueue();

	nodesExpanded = nodesGenerated = solutionLength = 0;

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

	printf("BFS Search function called\n\n");
	
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

	struct Node *initialNode = newNode(IA, NULL, 0, 0, 0);
	addToQueue(SearchFrontier, initialNode);

	do
	{
		i = 0;
		j = 0;
		int gapRow = 0, gapCol = 0, temp = -1;
		int allMatch = -1;
		int currentStateArray[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
		int childStateArray[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
		
		struct Node *nodeFromSearchQueue = removeFromQueue(SearchFrontier);
		addToQueue(VisitedList, nodeFromSearchQueue);

		allMatch = arrayMatching(nodeFromSearchQueue->state, TA);

		if (allMatch == 1)
		{
			printf("Solution found!\n");
			return;
		}

		int nodeMoveUP = validMovement(nodeFromSearchQueue->state, UP);
		int nodeMoveRIGHT = validMovement(nodeFromSearchQueue->state, RIGHT);
		int nodeMoveDOWN = validMovement(nodeFromSearchQueue->state, DOWN);
		int nodeMoveLEFT = validMovement(nodeFromSearchQueue->state, LEFT);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				currentStateArray[i][j] = nodeFromSearchQueue->state;
				nodeFromSearchQueue->state++;
				childStateArray[i][j] = currentStateArray[i][j];

				if (currentStateArray[i][j] == 0)
				{
					gapRow = i;
					gapCol = j;
				}
			}
		}

		if (nodeMoveUP == 1)
		{
			int temp = currentStateArray[gapRow - 1][gapCol];
			childStateArray[gapRow][gapCol] = temp;
			childStateArray[gapRow - 1][gapCol] = 0;

			struct Node *child = newNode(*childStateArray, nodeFromSearchQueue, UP, nodeFromSearchQueue->cost++, nodeFromSearchQueue->depth++);
			addToQueue(SearchFrontier, child);
		}
		else if (nodeMoveRIGHT == 1)
		{
			int temp = currentStateArray[gapRow][gapCol + 1];
			childStateArray[gapRow][gapCol] = temp;
			childStateArray[gapRow][gapCol + 1];

			struct Node *child = newNode(*childStateArray, nodeFromSearchQueue, RIGHT, nodeFromSearchQueue->cost++, nodeFromSearchQueue->depth++);
			addToQueue(SearchFrontier, child);
		}
		else if (nodeMoveDOWN == 1)
		{
			int temp = currentStateArray[gapRow + 1][gapCol];
			childStateArray[gapRow][gapCol] = temp;
			childStateArray[gapRow + 1][gapCol];

			struct Node *child = newNode(*childStateArray, nodeFromSearchQueue, DOWN, nodeFromSearchQueue->cost++, nodeFromSearchQueue->depth++);
			addToQueue(SearchFrontier, child);
		}
		else if (nodeMoveLEFT == 1)
		{
			int temp = currentStateArray[gapRow][gapCol - 1];
			childStateArray[gapRow][gapCol] = temp;
			childStateArray[gapRow][gapCol - 1];

			struct Node *child = newNode(*childStateArray, nodeFromSearchQueue, LEFT, nodeFromSearchQueue->cost++, nodeFromSearchQueue->depth++);
			addToQueue(SearchFrontier, child);
		}
	} while (SearchFrontier->front == SearchFrontier->rear == NULL);
}

void AstarSearch(int *IA, int *TA)
{
	printf("A* Search function called\n");
}