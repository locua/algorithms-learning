#include "HashTable.hpp"
#include <iostream>

HashTable::HashTable(long _a, long _c, long _m) {
    a = _a;
    c = _c;
    m = _m;

    tableElems = 0;

    buckets = new int[(int) _m];
    
    for (int i = 0; i < m; i++) {
        buckets[i] = 0;
    }
}

HashTable::~HashTable() {
    // delete [] buckets;
}

int HashTable::hashingVal(int x) {
	int val = ((a * x) + c) % m;
    return val;
}

void HashTable::insert(int key) {  
    int hashInd = hashingVal(key), k = 0, j;

    if (tableElems == hashInd) {
        extend();
        hashInd = hashingVal(key);    
    }
    do {
        j = (hashInd + k) % m;
        k++;
    } while (!freeTab(buckets[j]));

    buckets[j] = key;
    tableElems++;
}

void HashTable::extend() { 
    int *oldBucks = buckets;

    buckets = new int[(int) m*2];
    
    for (int i = 0; i < m; i++) {
        insert(oldBucks[i]);
    }
    
    delete [] oldBucks;
    m = m * 2;
}

bool HashTable::find(int key) {
    int hashInd = hashingVal(key);
    
    if (buckets[hashInd] == key) {
        return true;
    }
    else {        
        while (buckets[hashInd] != 0) {
            if (buckets[hashInd] == key ) {
                return true;
            }
            hashInd++;
        }
    }
 
    return false;

}

double HashTable::loadFactor() {
    return double(tableElems) / m;
}

bool HashTable::freeTab(int val) {
    return val == 0 || val == -1;
}

void HashTable::remove(int key) {
   int hashInd = hashingVal(key), k = 0, j;

   do {
       j = (hashInd + k) % m;
       k++;
   } while (buckets[j] != key);
   
   buckets[j] = -1;    

}
