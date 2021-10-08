#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

#define MAXQUEUE 10
typedef int Item;
// easily change to other defination without changing any other part
//typedef int Item;
typedef struct node
{
    Item item;
    struct node *next; // struct cannot contain the same struct
} Node;
typedef struct queue
{
    Node *front;
    Node *rear;
    int items; // count the item in the queue
} Queue;       // queue is a pointer point to Node
/* function prototypes */
/* operation: initialize a queue */
/* preconditions: pqueue points to a queue */
/* postconditions: the queue is initialized to empty */
void InitializeQueue(Queue *pqueue);

/* operation: determine if queue is empty */
/* pqueue points to an initialized queue */
/* postconditions: function returns True if queue is empty */
/* and returns False otherwise */
bool QueueIsEmpty(const Queue *pqueue);

/* operation: determine if queue is full */
/* pqueue points to an initialized queue */
/* postconditions: function returns True if queue is full */
/* and returns False otherwise */
bool QueueIsFull(const Queue *pqueue);

/* operation: determine number of items in queue */
/* pqueue points to an initialized queue */
/* postconditions: function returns number of items in queue */
int QueueItemCount(const Queue *pqueue);

/* operation: add item to rear of queue */
/* precondition: pq points to previously initialized queue */
/* item is to be placed at rear of queue */
/* postcondition: if queue is not empty, item is placed at */
/* rear of queue and function returns */
/* True; otherwise, queue is unchanged and */
/* function returns False */
bool EnQueue(Item item, Queue *pq);

/* operation: remove item from front of queue */
/* precondition: pq points to previously initialized queue */
/* postcondition: if queue is not empty, item at head of */
/* queue is copied to *pitem and deleted from */
/* queue, and function returns True; if the */
/* operation empties the queue, the queue is */
/* reset to empty. If the queue is empty to */
/* begin with, queue is unchanged and the */
/* function returns False */
bool DeQueue(Item *pitem, Queue *pq);

/* operation: free allocated memory, if any */
/* pqueue points to an initialized queue */
/* postconditions: any memory allocated for the queue is freed */
/* and the queue is set to empty */
void EmptyTheQueue(Queue *pqueue);
#endif