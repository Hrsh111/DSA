/*
 * LeetCode #242 - Valid Anagram
 * https://leetcode.com/problems/valid-anagram/
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a different
 * word or phrase, typically using all the original letters exactly once.
 *
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 *
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 * Constraints:
 * - 1 <= s.length, t.length <= 5 * 10^4
 * - s and t consist of lowercase English letters.
 *
 * Follow up: What if the inputs contain Unicode characters? How would you adapt
 * your solution to such a case?
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    cout << "Test 1: " << (sol.isAnagram("anagram", "nagaram") ? "true" : "false") << endl;
    // Expected: true

    // Test case 2
    cout << "Test 2: " << (sol.isAnagram("rat", "car") ? "true" : "false") << endl;
    // Expected: false

    // Test case 3
    cout << "Test 3: " << (sol.isAnagram("listen", "silent") ? "true" : "false") << endl;
    // Expected: true

    return 0;
}
