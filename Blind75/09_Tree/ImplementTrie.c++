/*
 * LeetCode #208 - Implement Trie (Prefix Tree)
 * https://leetcode.com/problems/implement-trie-prefix-tree/
 *
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to
 * efficiently store and retrieve keys in a dataset of strings. There are various
 * applications of this data structure, such as autocomplete and spellchecker.
 *
 * Implement the Trie class:
 * - Trie() Initializes the trie object.
 * - void insert(String word) Inserts the string word into the trie.
 * - boolean search(String word) Returns true if the string word is in the trie
 *   (i.e., was inserted before), and false otherwise.
 * - boolean startsWith(String prefix) Returns true if there is a previously
 *   inserted string word that has the prefix prefix, and false otherwise.
 *
 * Example 1:
 * Input
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * Output
 * [null, null, true, false, true, null, true]
 *
 * Explanation
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // return True
 * trie.search("app");     // return False
 * trie.startsWith("app"); // return True
 * trie.insert("app");
 * trie.search("app");     // return True
 *
 * Constraints:
 * - 1 <= word.length, prefix.length <= 2000
 * - word and prefix consist only of lowercase English letters.
 * - At most 3 * 10^4 calls in total will be made to insert, search, and startsWith.
 */

#include <iostream>
#include <string>
using namespace std;

class Trie {
public:
    Trie() {
        // TODO: Initialize your data structure here

    }

    void insert(string word) {
        // TODO: Implement your solution here

    }

    bool search(string word) {
        // TODO: Implement your solution here

    }

    bool startsWith(string prefix) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Trie trie;

    trie.insert("apple");
    cout << "Test 1 (search 'apple'): " << (trie.search("apple") ? "true" : "false") << endl;
    // Expected: true

    cout << "Test 2 (search 'app'): " << (trie.search("app") ? "true" : "false") << endl;
    // Expected: false

    cout << "Test 3 (startsWith 'app'): " << (trie.startsWith("app") ? "true" : "false") << endl;
    // Expected: true

    trie.insert("app");
    cout << "Test 4 (search 'app'): " << (trie.search("app") ? "true" : "false") << endl;
    // Expected: true

    return 0;
}
