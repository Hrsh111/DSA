/*
 * LeetCode #146 - LRU Cache
 * https://leetcode.com/problems/lru-cache/
 *
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 * Implement get(key) and put(key, value) in O(1) time.
 *
 * System Design Relevance: Cache eviction policy used in Redis, Memcached, CDNs
 */
#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> map;
    Node* head; // dummy head (most recent)
    Node* tail; // dummy tail (least recent)

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        Node* node = map[key];
        remove(node);
        insertAtHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            node->val = value;
            remove(node);
            insertAtHead(node);
        } else {
            if ((int)map.size() == capacity) {
                Node* lru = tail->prev;
                remove(lru);
                map.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            map[key] = node;
            insertAtHead(node);
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;    // 1
    cache.put(3, 3);                  // evicts key 2
    cout << cache.get(2) << endl;    // -1
    cache.put(4, 4);                  // evicts key 1
    cout << cache.get(1) << endl;    // -1
    cout << cache.get(3) << endl;    // 3
    cout << cache.get(4) << endl;    // 4
    return 0;
}
