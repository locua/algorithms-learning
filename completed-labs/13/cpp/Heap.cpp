#include "Heap.hpp"
#include <iostream>

unsigned int parent(unsigned int i) {
  return (i-1)/2;
}

unsigned int left(unsigned int i) {
  return 2*i+1;
}

unsigned int right(unsigned int i) {
  return 2*i+2;
}

Heap::Heap(unsigned int len) {
    heap_size = 0; 
    array = std::vector<int>(len);
}

Heap::Heap(std::vector<int> source, bool incremental) {
    heap_size = 0;
    if (incremental) { 
        array = std::vector<int>(source.size());
        for (int i = 0; i < source.size(); i++) {
            insert(source[i]);
        }
    }
    else if (!incremental){
        array = source;
        // counter.add(array.size());
        buildMaxHeap();
    }
}

void Heap::maxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < heap_size && array[l] > array[largest]) {
        largest = l;
    }
    if (r < heap_size && array[r] > array[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(&array[i], &array[largest]);
        maxHeapify(largest);
    }
}

void Heap::buildMaxHeap() {
    heap_size = array.size();
    for (int i = (array.size()/2)-1; i >= 0; i--) {
        maxHeapify(i);
    }
}

int Heap::maximum() {
    return array.front();
}

void Heap::insert(int k) {
    if (array.empty()) {
        array.resize(1);
    }
    
    if (array.size() == heap_size) {
        array.resize(array.size() + 1);
    }
    // counter.add(1);
    array[heap_size] = k;
    int i = heap_size;
    heap_size++;
    while (i > 0 && array[parent(i)] < array[i]) {
        swap(&array[i], &array[parent(i)]);
        i = parent(i);
        // counter.add(1);
    }
}
    
int Heap::extractMax() {
    int maxVal = array[0];
    array[0] = array[heap_size - 1];
    heap_size--;
    maxHeapify(0);
    return maxVal;
}

std::vector<int> Heap::sort() {
    buildMaxHeap();

    while (heap_size > 0) {
        int i = heap_size;
        array[i-1] = extractMax();
    }
    return array;
}

void Heap::swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
    // counter.add(2);
}
