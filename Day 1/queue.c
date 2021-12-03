#include <stdlib.h>
#include <string.h>

struct Queue {
    int front, rear, size;
    unsigned int capacity;
    int* queueArray;
};

struct Queue* createQueue(unsigned int capacity) {

    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));

    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity-1;
    queue->queueArray = (int*) malloc(queue->capacity * sizeof(int));

    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        return;
    }
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->queueArray[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return 0;
    int item = queue->queueArray[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return 0;
    return queue->queueArray[queue->front];
}
 
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return 0;
    return queue->queueArray[queue->rear];
}