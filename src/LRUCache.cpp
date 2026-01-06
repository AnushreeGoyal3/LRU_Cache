#include "LRUCache.h"

// Node definition
Node::Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}

LRUCache::LRUCache(int cap) {
    capacity = cap;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
}

void LRUCache::remove(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void LRUCache::insertAfterHead(Node* node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}

int LRUCache::get(int key) {
    if (cache.find(key) == cache.end()) return -1;
    Node* node = cache[key];
    remove(node);
    insertAfterHead(node);
    return node->value;
}

void LRUCache::put(int key, int value) {
    if (cache.find(key) != cache.end()) {
        Node* node = cache[key];
        node->value = value;
        remove(node);
        insertAfterHead(node);
    } else {
        if (cache.size() == capacity) {
            Node* lru = tail->prev;
            cache.erase(lru->key);
            remove(lru);
            delete lru;
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insertAfterHead(newNode);
    }
}
