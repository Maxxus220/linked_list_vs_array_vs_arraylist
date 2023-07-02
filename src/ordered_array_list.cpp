#include "../include/ordered_array_list.h"

OrderedArrayList::OrderedArrayList() {
    size = 0;
    capacity = STARTING_CAPACITY;
    array = new int[capacity];
}

OrderedArrayList::~OrderedArrayList() {
    delete[] array;
}

void OrderedArrayList::add(int val) {
    if(size == capacity) {
        capacity *= 2;
        int* newArray = new int[capacity];
        for(int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

    for(int i = 0; i < size; i++) {
        if(array[i] > val) {
            for(int j = size-1; j >= i; j--) {
                array[j+1] = array[j]; 
            }
            array[i] = val;
            size++;
            return;
        }
    }

    array[size] = val;
    size++;
}

bool OrderedArrayList::remove(int index) {
    if(index >= size || index < 0) {
        return false;
    }

    for(int i = index; i < size-1; i++) {
        array[i] = array[i+1];
    }
    size--;
    
    return true;
}
