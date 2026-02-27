/*
 * LeetCode #5 - Longest Palindromic Substring
 * https://leetcode.com/problems/longest-palindromic-substring/
 *
 * Given a string s, return the longest palindromic substring in s.
 *
 * Example 1:
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 *
 * Example 2:
 * Input: s = "cbbd"
 * Output: "bb"
 *
 * Constraints:
 * - 1 <= s.length <= 1000
 * - s consist of only digits and English letters.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    cout << "Test 1: \"" << sol.longestPalindrome("babad") << "\"" << endl;
    // Expected: "bab" or "aba"

    // Test case 2
    cout << "Test 2: \"" << sol.longestPalindrome("cbbd") << "\"" << endl;
    // Expected: "bb"

    // Test case 3
    cout << "Test 3: \"" << sol.longestPalindrome("a") << "\"" << endl;
    // Expected: "a"

    return 0;
}
