#include <cstdlib>
#include <stdio.h>
#include <chrono>
#include <stdlib.h>
#include "../include/main.h"
#include "../include/ordered_linked_list.h"
#include "../include/ordered_array.h"
#include "../include/ordered_array_list.h"

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Program requires exactly one argument");
        return 1;
    }
    
    int numElements = std::atoi(argv[1]);
    if(numElements == 0) {
        printf("Argument must be a valid # of elements");
        return 1;
    }

    testOrderedLinkedList(numElements);
    testOrderedArray(numElements);
    testOrderedArrayList(numElements);
}

void testOrderedLinkedList(int numElements) {
    OrderedLinkedList* list = new OrderedLinkedList();

    auto startTime = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < numElements; i++) {
        list->add(rand());
    }

    for(int i = 0; i < numElements; i++) {
        list->remove(rand()%(list->size));
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    printf("OrderedLinkedList: %lldms\n", totalTime.count());
}

void testOrderedArray(int numElements) {
    OrderedArrayList* list = new OrderedArrayList();

    auto startTime = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < numElements; i++) {
        list->add(rand());
    }

    for(int i = 0; i < numElements; i++) {
        list->remove(rand()%(list->size));
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    printf("OrderedArrayList: %lldms\n", totalTime.count());
}

void testOrderedArrayList(int numElements) {
    OrderedArray* list = new OrderedArray(numElements);

    auto startTime = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < numElements; i++) {
        list->add(rand());
    }

    for(int i = 0; i < numElements; i++) {
        list->remove(rand()%(list->size));
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    printf("OrderedArray: %lldms\n", totalTime.count());
}
