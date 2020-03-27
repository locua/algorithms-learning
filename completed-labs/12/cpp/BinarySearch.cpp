#include "BinarySearch.hpp"

bool BinarySearch::search(int *array, int key, size_t lo, size_t hi) {
    int mid = lo + (hi - 1 - lo) / 2;
    // int mid = (lo+hi-1) / 2;
    if (lo == hi) {
        return false;
    }
    else if (array[mid] == key) {
        return true;
    }    
    else if (key < array[mid]) {
        return search(array, key, lo, mid);
    }
    else {
        return search(array, key, mid + 1, hi);
    }
        
    return true;
}

int BinarySearch::count(int *array, int key, size_t lo, size_t hi) {
    int counter = 0;
    
    while (lo < hi) {
        counter++;
       
        int mid = lo + (hi - 1 - lo) / 2;

        if (lo == hi) {
            return 0;
        }
        else if (array[mid] == key) {
            return counter;
        }    
        else if (key < array[mid]) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }

    return counter;
}

