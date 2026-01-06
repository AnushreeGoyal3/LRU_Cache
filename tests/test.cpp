#include "../include/LRUCache.h"
#include <iostream>
using namespace std;

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // 1
    cache.put(3, 3);               // evicts key 2
    cout << cache.get(2) << endl; // -1
    cache.put(4, 4);               // evicts key 1
    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cout << cache.get(4) << endl; // 4
}
