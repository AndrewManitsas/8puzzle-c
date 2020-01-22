#if !defined(SEARCH)
#define SEARCH

struct Queue *createQueue();
int validMovement(int *, int);
void testNode(int *, int *);
void testQueue(int *, int *);
void BFSSearch(int *, int *);
void AstarSearch(int *, int *);

#endif // SEARCH
