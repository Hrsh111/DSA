/*
 * LeetCode #460 - LFU Cache
 * https://leetcode.com/problems/lfu-cache/
 *
 * Design a data structure for a Least Frequently Used (LFU) cache.
 * Implement get(key) and put(key, value) in O(1) time.
 *
 * System Design Relevance: Alternative eviction policy when some items
 * are significantly more popular than others.
 */
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyVal;           // key → {value, freq}
    unordered_map<int, list<int>> freqList;               // freq → list of keys
    unordered_map<int, list<int>::iterator> keyIter;      // key → iterator in freq list

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    int get(int key) {
        if (keyVal.find(key) == keyVal.end()) return -1;
        int freq = keyVal[key].second;
        freqList[freq].erase(keyIter[key]);
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq) minFreq++;
        }
        keyVal[key].second++;
        freqList[freq + 1].push_back(key);
        keyIter[key] = prev(freqList[freq + 1].end());
        return keyVal[key].first;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;
        if (keyVal.find(key) != keyVal.end()) {
            keyVal[key].first = value;
            get(key);
            return;
        }
        if ((int)keyVal.size() >= capacity) {
            int evict = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            if (freqList[minFreq].empty()) freqList.erase(minFreq);
            keyVal.erase(evict);
            keyIter.erase(evict);
        }
        keyVal[key] = {value, 1};
        freqList[1].push_back(key);
        keyIter[key] = prev(freqList[1].end());
        minFreq = 1;
    }
};

int main() {
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;    // 1 (freq of key 1 = 2)
    cache.put(3, 3);                  // evicts key 2 (least frequent)
    cout << cache.get(2) << endl;    // -1
    cout << cache.get(3) << endl;    // 3
    cache.put(4, 4);                  // evicts key 3 (freq 1, key 1 has freq 2)
    cout << cache.get(1) << endl;    // 1
    cout << cache.get(3) << endl;    // -1
    cout << cache.get(4) << endl;    // 4
    return 0;
}
