#include "../include/ordered_array.h"

OrderedArray::OrderedArray(int capacity) {
    array = new int[capacity];
    size = 0;
}

OrderedArray::~OrderedArray() {
    delete[] array;
}

void OrderedArray::add(int val) {
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

bool OrderedArray::remove(int index) {
    if(index >= size || index < 0) {
        return false;
    }

    for(int i = index; i < size; i++) {
        array[i] = array[i+1];
    }

    size--;

    return true;
}
