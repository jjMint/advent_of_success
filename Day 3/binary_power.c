#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN_LEN 255
#define binarySize 12


struct binarySignal {
    int oneCount;
    int zeroCount;
};

int calculate_power(FILE *binaryInput) {

    char *binaryLine;
    char line[IN_LEN] = {0};
    int gamma;
    char gammaBin[binarySize];
    int epsilon;
    struct binarySignal binarySignals[binarySize] = {0};

    while (fgets(line, IN_LEN, binaryInput)) {
        for (int i = 0; i < binarySize; i++) {
            if (atoi(line) & (1 << (i-1))) {
                binarySignals[i].oneCount++;
            }
            else {
                binarySignals[i].zeroCount++;
            }
        }
    }
    for (int i = binarySize; i > 0; i--) {
        if (binarySignals[i].oneCount > binarySignals[i].zeroCount && i == 0) {
            gamma = (i*2) + 1;
            epsilon = (i*2) + 0;
        }
        if (binarySignals[i].oneCount > binarySignals[i].zeroCount && i != 0) {
            gamma = (gamma*2) + 1;
            epsilon = (epsilon*2) + 0;
        }
        if (binarySignals[i].oneCount < binarySignals[i].zeroCount && i == 0) {
            gamma = (i*2) + 0;
            epsilon = (i*2) + 1;
        }
        if (binarySignals[i].oneCount < binarySignals[i].zeroCount && i != 0) {
            gamma = (gamma*2) + 0;
            epsilon = (epsilon*2) + 1;
        }
    }
    printf("Values for gamma: %d and epsilon: %d\n", gamma, epsilon);
    return gamma * epsilon;
}

int main (int argc, char **argv) {

    if (argc < 2) {
        printf("Please provide a text file with the binary inputs\n");
        return -1;
    }

    char *filePath = (char *) malloc(255*sizeof(char));
    FILE *binaryInput;

    filePath = argv[1];
    binaryInput = fopen(filePath, "r");
    printf("Power draw is: %d\n", calculate_power(binaryInput));
}