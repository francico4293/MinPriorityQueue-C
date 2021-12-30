/**
 * @file main.c
 * @author Colin Francis
 * @brief Minimum priority queue implementation using an array based
 * heap in C
 * @version 0.1
 * @date 2021-12-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>

struct dynamicArray {
    int size;  // the current number of elements in the array
    int capacity;  // the maximum number of elements the array can hold
    int *array;  // the underlying static array
};

/**
 * @brief 
 * 
 * @return struct dynamicArray 
 */
struct dynamicArray newDynamicArray(void) {
    struct dynamicArray dynArr = {.size=0, .capacity=5, .array=NULL};
    dynArr.array = (int*) malloc(dynArr.capacity * sizeof(struct dynamicArray));

    return dynArr;
}

/**
 * @brief Driver code for minimum priority queue implementation
 * 
 * @return int 
 */
int main(void) {
    struct dynamicArray priorityQueue = newDynamicArray();

    return 0;
}
