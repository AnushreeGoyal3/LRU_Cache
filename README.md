# LRU Cache

## Overview
LRU Cache implementation in C++ using unordered_map and doubly linked list. Achieves O(1) `get` and `put` operations.

## Features
- O(1) lookup and insertion
- Automatic eviction of least recently used items
- Supports generic capacity

## Usage
```cpp
LRUCache cache(2);
cache.put(1,1);
cache.get(1); // returns 1
