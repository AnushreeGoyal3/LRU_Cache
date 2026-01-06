#pragma once
#include <unordered_map>
using namespace std;

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v);
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void remove(Node* node);
    void insertAfterHead(Node* node);

public:
    LRUCache(int cap);
    int get(int key);
    void put(int key, int value);
};
