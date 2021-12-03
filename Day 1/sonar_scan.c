#include <stdio.h>
#include "queue.c"

#define IN_LEN 255

// Here we do a window scan using a queue struct as our rolling window
int window_step_scan(FILE *sonarDepths) {
    
    int initialSum;
    int currentSum;
    int depthValue;
    char line[IN_LEN] = {0};
    unsigned int numberLarger = 0;
    struct Queue* queue = createQueue(3);

    // Loop through the depths and add to the queue, when at each depth check the sum 
    // before adding the newest depth and removing the other
    while (fgets(line, IN_LEN, sonarDepths)) {
        
        depthValue = atoi(line);
        enqueue(queue, depthValue);

        if (isFull(queue)) {
            currentSum = queue->queueArray[0] + queue->queueArray[1] + queue->queueArray[2];
            dequeue(queue);
        }
        if (currentSum > initialSum && initialSum != 0){
            numberLarger++;
        }
        initialSum = currentSum;
    }
    if (fclose(sonarDepths)) {
        return EXIT_FAILURE;
    }
    return numberLarger;
}

// Here we do a single step scan per each depth
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

// ------------------------------------------------------------------------
// On run provide the sonar depths text file as input for the file path
// ------------------------------------------------------------------------
int main(int argc, char **argv) {

    if (argc < 2) {
        printf("Please provide a text file with depths\n");
        return -1;
    }

    char *filePath = (char *) malloc(255*sizeof(char));
    FILE *sonarDepths;

    filePath = argv[1];
    sonarDepths = fopen(filePath, "r");
    printf("Number of singular step Depth Increases: %d\n", single_step_scan(sonarDepths));

    sonarDepths = fopen(filePath, "r");
    printf("Number of window step Depth Increases: %d\n", window_step_scan(sonarDepths));
}