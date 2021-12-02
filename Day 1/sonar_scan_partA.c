#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN_LEN 99

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

// Function to get front of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return 0;
    return queue->queueArray[queue->front];
}
 
// Function to get rear of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return 0;
    return queue->queueArray[queue->rear];
}

int window_step_scan(FILE *sonarDepths) {
    
    int initialSum;
    int current;
    char line[IN_LEN] = {0};
    unsigned int numberLarger = 0;
    struct Queue* queue = createQueue(3);

    while (fgets(line, IN_LEN, sonarDepths)) {
        current = atoi(line);
        enqueue(queue, current);
        if (current > initialSum && initialDepth != 0){
            numberLarger++;
        }
        initialSum = current;
    }
    if (fclose(sonarDepths)) {
        return EXIT_FAILURE;
    }
    return numberLarger;
}

int single_step_scan(FILE *sonarDepths) {
    
    int initialDepth;
    int current;
    char line[IN_LEN] = {0};
    unsigned int numberLarger = 0;

    while (fgets(line, IN_LEN, sonarDepths)) {
        current = atoi(line);
        if (current > initialDepth && initialDepth != 0){
            numberLarger++;
        }
        initialDepth = current;
    }
    if (fclose(sonarDepths)) {
        return EXIT_FAILURE;
    }
    return numberLarger;
}

int main(int argc, char **argv) {

    if (argc < 2) {
        printf("Please provide a text file with depths\n");
        return 0;
    }

    char *filePath = (char *) malloc(255*sizeof(char));
    FILE *sonarDepths;

    filePath = argv[1];
    sonarDepths = fopen(filePath, "r");
    printf("Number of singular step Depth Increases: %d\n", single_step_scan(sonarDepths));

}