#include <stdio.h>
#include <stdlib.h>

#define IN_LEN 255

struct SubmarinePosition {
    int horizontalPosition;
    int depthPosition;
    int aim;
};

int determine_final_position_advanced(FILE *submarineCourse) {

    char *changeAmount;
    char line[IN_LEN] = {0};
    int finalPosition = 0;
    struct SubmarinePosition submarinePosition = {0};

    while (fgets(line, IN_LEN, submarineCourse)) {
        strtok_r(line, " ", &changeAmount);
        if (strcmp(line, "forward") == 0) {
            submarinePosition.horizontalPosition += atoi(changeAmount);
            submarinePosition.depthPosition += atoi(changeAmount) * submarinePosition.aim;
        }
        if (strcmp(line, "up") == 0) {
            submarinePosition.aim -= atoi(changeAmount);
        }
        if (strcmp(line, "down") == 0) {
            submarinePosition.aim += atoi(changeAmount);
        }
    }
    finalPosition = submarinePosition.horizontalPosition * submarinePosition.depthPosition;
    if (fclose(submarineCourse)) {
        return EXIT_FAILURE;
    }
    return finalPosition;
}

int determine_final_position_simple(FILE *submarineCourse) {

    char *changeAmount;
    char line[IN_LEN] = {0};
    int finalPosition = 0;
    struct SubmarinePosition submarinePosition = {0};

    while (fgets(line, IN_LEN, submarineCourse)) {
        strtok_r(line, " ", &changeAmount);
        if (strcmp(line, "forward") == 0) {
            submarinePosition.horizontalPosition += atoi(changeAmount);
        }
        if (strcmp(line, "up") == 0) {
            submarinePosition.depthPosition -= atoi(changeAmount);
        }
        if (strcmp(line, "down") == 0) {
            submarinePosition.depthPosition += atoi(changeAmount);
        }
    }
    finalPosition = submarinePosition.horizontalPosition * submarinePosition.depthPosition;
    if (fclose(submarineCourse)) {
        return EXIT_FAILURE;
    }
    return finalPosition;
}


int main (int argc, char **argv) {

    if (argc < 2) {
        printf("Please provide a text file with the plotted course\n");
        return -1;
    }

    char *filePath = (char *) malloc(255*sizeof(char));
    FILE *submarineCourse;

    filePath = argv[1];
    submarineCourse = fopen(filePath, "r");
    printf("Final submarine position (simple) product: %d\n", determine_final_position_simple(submarineCourse));

    submarineCourse = fopen(filePath, "r");
    printf("Final submarine position (advanced) product: %d\n", determine_final_position_advanced(submarineCourse));
}