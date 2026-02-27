/*
 * LeetCode #706 - Design HashMap
 * https://leetcode.com/problems/design-hashmap/
 *
 * System Design Relevance: Understanding hash tables is fundamental
 * to databases (hash indexes), caching, and distributed systems.
 */
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class MyHashMap {
    static const int SIZE = 10007; // prime number for better distribution
    vector<list<pair<int, int>>> buckets;

    int hash(int key) { return key % SIZE; }

public:
    MyHashMap() : buckets(SIZE) {}

    void put(int key, int value) {
        auto& bucket = buckets[hash(key)];
        for (auto& [k, v] : bucket) {
            if (k == key) { v = value; return; }
        }
        bucket.push_back({key, value});
    }

    int get(int key) {
        auto& bucket = buckets[hash(key)];
        for (auto& [k, v] : bucket) {
            if (k == key) return v;
        }
        return -1;
    }

    void remove(int key) {
        auto& bucket = buckets[hash(key)];
        bucket.remove_if([key](auto& p) { return p.first == key; });
    }
};

int main() {
    MyHashMap map;
    map.put(1, 1);
    map.put(2, 2);
    cout << map.get(1) << endl;   // 1
    cout << map.get(3) << endl;   // -1
    map.put(2, 1);
    cout << map.get(2) << endl;   // 1
    map.remove(2);
    cout << map.get(2) << endl;   // -1
    return 0;
}
