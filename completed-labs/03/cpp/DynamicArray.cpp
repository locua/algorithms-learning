#include "DynamicArray.hpp"

DynamicArray::DynamicArray(size_t size) {
    makeArray(size);
}

size_t DynamicArray::length() {
    return arrayLengthPrime;
}

int DynamicArray::select(size_t k) {        
    if (k < arrayLengthPrime){
        return array[k];	
    }

    return -1;
}

void DynamicArray::store(int o, size_t k) {
    if (k < arrayLengthPrime) {
        array[k] = o;  
        counter.add(1);
    }
}

void DynamicArray::push(int o) {
    if (length() == arrayLength) {
        extend();
    }

    arrayLengthPrime++;
    store(o, arrayLengthPrime - 1);
}

int DynamicArray::pop() {
    int poppedItem = select(arrayLengthPrime - 1);
    store(0, arrayLengthPrime - 1);
    arrayLengthPrime--;

    return poppedItem;
}

void DynamicArray::extend() {
    int* oldArray = array;
    int oldLengthPrime = arrayLengthPrime;

    makeArray(arrayLength * arrayLength);

    for (int i = 0; i < oldLengthPrime; ++i){
        push(oldArray[i]);
    }

}

void DynamicArray::makeArray(size_t size) {
    array = new int[size];
    arrayLength = size;

    for (int i = 0; i < size; ++i) {
        array[i] = 0;
    }

    arrayLengthPrime = 0;
}

size_t DynamicArray::arrayOverhead(){
   return arrayLength - arrayLengthPrime;
}
