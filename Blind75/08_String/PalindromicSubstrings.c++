/*
 * LeetCode #647 - Palindromic Substrings
 * https://leetcode.com/problems/palindromic-substrings/
 *
 * Given a string s, return the number of palindromic substrings in it.
 *
 * A string is a palindrome when it reads the same backward as forward.
 * A substring is a contiguous sequence of characters within the string.
 *
 * Example 1:
 * Input: s = "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 *
 * Example 2:
 * Input: s = "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 *
 * Constraints:
 * - 1 <= s.length <= 1000
 * - s consists of lowercase English letters.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    cout << "Test 1: " << sol.countSubstrings("abc") << endl;
    // Expected: 3

    // Test case 2
    cout << "Test 2: " << sol.countSubstrings("aaa") << endl;
    // Expected: 6

    // Test case 3
    cout << "Test 3: " << sol.countSubstrings("abba") << endl;
    // Expected: 6

    return 0;
}
