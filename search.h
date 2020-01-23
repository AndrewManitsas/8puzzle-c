#if !defined(SEARCH)
#define SEARCH

struct Node *newNode(int *, struct Node *, int , int , int);
struct Queue *createQueue();
void addToQueue(struct Queue *, struct Node *);
struct Node *removeFromQueue(struct Queue *);
int validMovement(int *, int);
void testNode(int *, int *); //Used only for debugging and testing
void testQueue(int *, int *); //Used only for debugging and testing
int arrayMatching(int *, int *);
void BFSSearch(int *, int *);
void AstarSearch(int *, int *);

#endif // SEARCH