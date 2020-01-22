#if !defined(QUEUE)
#define QUEUE

struct Queue *createQueue();
void addToQueue(struct Queue *, struct Node *);
struct Node *removeFromQueue(struct Queue *);
int validMovement(int *, int);
void testNode(int *, int *);
void testQueue(int *, int *);

#endif // QUEUE
