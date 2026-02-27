/*
 * LeetCode #139 - Word Break
 * https://leetcode.com/problems/word-break/
 *
 * Given a string s and a dictionary of strings wordDict, return true if s can
 * be segmented into a space-separated sequence of one or more dictionary words.
 * Note that the same word in the dictionary may be reused multiple times in the
 * segmentation.
 *
 * Example 1:
 * Input: s = "leetcode", wordDict = ["leet","code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet code".
 *
 * Example 2:
 * Input: s = "applepenapple", wordDict = ["apple","pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
 * Note that you are allowed to reuse a dictionary word.
 *
 * Example 3:
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: false
 *
 * Constraints:
 * - 1 <= s.length <= 300
 * - 1 <= wordDict.length <= 1000
 * - 1 <= wordDict[i].length <= 20
 * - s and wordDict[i] consist of only lowercase English letters.
 * - All the strings of wordDict are unique.
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<string> dict1 = {"leet", "code"};
    cout << "Test 1: " << (sol.wordBreak("leetcode", dict1) ? "true" : "false") << endl;
    // Expected: true

    // Test case 2
    vector<string> dict2 = {"apple", "pen"};
    cout << "Test 2: " << (sol.wordBreak("applepenapple", dict2) ? "true" : "false") << endl;
    // Expected: true

    // Test case 3
    vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << "Test 3: " << (sol.wordBreak("catsandog", dict3) ? "true" : "false") << endl;
    // Expected: false

    return 0;
}
