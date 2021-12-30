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
#include <stdbool.h>

#define ARR_CAP 0.75  // max allowed array ratio, i.e., size / capacity

struct dynamicArray {
    int size;  // the current number of elements in the array
    int capacity;  // the maximum number of elements the array can hold
    int *array;  // the underlying static array
};

/**
 * @brief Prints the elements in the priority queue and displays the current
 * size and capacity of the dynamic array
 * 
 * @param dynArrPtr The address of the dynamic array struct
 */
void printPriorityQueue(struct dynamicArray *dynArrPtr) {
    printf("Priority Queue (%d/%d): [", dynArrPtr->size, dynArrPtr->capacity);

    if (dynArrPtr->size == 0) {
        printf("]\n");
        return;
    }

    for (int index = 0; index < dynArrPtr->size; index++) {
        if (index < dynArrPtr->size - 1) {
            printf("%d, ", *(dynArrPtr->array + index));
        } else {
            printf("%d]\n", *(dynArrPtr->array + index));
        }
    }
}

/**
 * @brief Creates a new dynamic array
 * 
 * @return struct dynamicArray A struct used for a dynamic array implementation.
 * The struct holds size, capacity, and a pointer to the underlying static array
 */
struct dynamicArray newDynamicArray(void) {
    // declare and initialize a dynamic array struct
    struct dynamicArray dynArr = {.size=0, .capacity=5, .array=NULL};
    
    // allocate memory on the heap for the underlying static array
    dynArr.array = (int*) malloc(dynArr.capacity * sizeof(struct dynamicArray));

    return dynArr;  // return dynamic array struct
}

/**
 * @brief Transfers current array elements to a new array with double the
 * capacity of the original array
 * 
 * @param dynArrPtr The address of the dynamic array struct
 */
void upSizeArray(struct dynamicArray *dynArrPtr) {
    // allocate memory on the heap for the new static array
    int *newArray = (int*) malloc(2 * dynArrPtr->capacity * sizeof(int));

    // transfer array elements to new array
    for (int index = 0; index < dynArrPtr->size; index++) {
        newArray[index] = *(dynArrPtr->array + index);
    }

    // set the dynamic array struct member "capacity" to 2x
    dynArrPtr->capacity = 2 * dynArrPtr->capacity;

    // free original array and set array member to new array address
    free(dynArrPtr->array);
    dynArrPtr->array = newArray;
}

/**
 * @brief Pushes a new value to the min heap
 * 
 * @param value The value to push
 * @param dynArrPtr The address of the dynamic array struct
 */
void heapPush(int value, struct dynamicArray *dynArrPtr) {
    // set current index and the associated parent index
    int currIndex = dynArrPtr->size;
    int parentIndex = (currIndex - 1) / 2;
    int temp = 0;

    // check if the new element being added will exceed array capacity
    if ((float) (dynArrPtr->size + 1) / (float) dynArrPtr->capacity >= ARR_CAP) {
        upSizeArray(dynArrPtr);  // resize the underlying static array
    }

    // add value to next open spot in array
    *(dynArrPtr->array + dynArrPtr->size) = value;

    // percolate added value up until root is reached or until value is greater than the
    // value of its parent
    while (currIndex > 0 && *(dynArrPtr->array + currIndex) < *(dynArrPtr->array + parentIndex)) {
        temp = *(dynArrPtr->array + parentIndex);
        *(dynArrPtr->array + parentIndex) = *(dynArrPtr->array + currIndex);
        *(dynArrPtr->array + currIndex) = temp;

        currIndex = parentIndex;
        parentIndex = (currIndex - 1) / 2;
    }

    dynArrPtr->size++;  // increment array size
}

/**
 * @brief 
 * 
 * @param dynArrPtr 
 * @return int 
 */
int heapPop(struct dynamicArray *dynArrPtr) {
    int minValue = *(dynArrPtr->array);
    int parentIndex = 0;
    int rightChildIndex = (2 * parentIndex) + 1;
    int leftChildIndex = (2 * parentIndex) + 2;
    int *statArrPtr = dynArrPtr->array;

    *(dynArrPtr->array) = *(dynArrPtr->array + dynArrPtr->size - 1);
    dynArrPtr->size--;
    
    while (true) {
        // the parent has left and right children
        if (rightChildIndex < dynArrPtr->size - 1 && leftChildIndex < dynArrPtr->size - 1) {
            // the parent value is greater than both children - swap with min
            if (statArrPtr[parentIndex] > statArrPtr[rightChildIndex] && statArrPtr[parentIndex] > statArrPtr[leftChildIndex]) {
            
            // the parent value is greater than only the right child
            } else if (statArrPtr[parentIndex] > statArrPtr[rightChildIndex]) {
            
            // the parent value is greater than only the left child
            } else if (statArrPtr[parentIndex] > statArrPtr[leftChildIndex]) {
            
            // the parent value is less than both children
            } else {    
                return;  // exit function
            }
        // the parent only has a right child
        } else if (rightChildIndex < dynArrPtr->size - 1) {
        
        // the parent only has a left child
        } else if (leftChildIndex < dynArrPtr->size - 1) {
        
        // the parent doesn't have children
        } else {

        }

        // update left and right child indices based on new parent index
        leftChildIndex = (2 * parentIndex) + 1;
        rightChildIndex = (2 * parentIndex) + 2;
    }
}

/**
 * @brief Driver code for minimum priority queue implementation
 * 
 * @return int 
 */
int main(void) {
    struct dynamicArray priorityQueue = newDynamicArray();

    printPriorityQueue(&priorityQueue);

    heapPush(20, &priorityQueue);
    printPriorityQueue(&priorityQueue);

    heapPush(15, &priorityQueue);
    printPriorityQueue(&priorityQueue);

    heapPush(5, &priorityQueue);
    printPriorityQueue(&priorityQueue);

    heapPush(10, &priorityQueue);
    printPriorityQueue(&priorityQueue);

    heapPush(1, &priorityQueue);
    printPriorityQueue(&priorityQueue);

    heapPop(&priorityQueue);

    return 0;
}
