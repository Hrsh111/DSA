/*
 * LeetCode #269 - Alien Dictionary (Premium)
 * https://leetcode.com/problems/alien-dictionary/
 *
 * There is a new alien language that uses the English alphabet. However, the
 * order of the letters is unknown to you.
 *
 * You are given a list of strings words from the alien language's dictionary,
 * where the strings in words are sorted lexicographically by the rules of this
 * new language.
 *
 * Return a string of the unique letters in the new alien language sorted in
 * lexicographically increasing order by the new language's rules. If there is
 * no solution, return "". If there are multiple solutions, return any of them.
 *
 * Example 1:
 * Input: words = ["wrt","wrf","er","ett","rftt"]
 * Output: "wertf"
 *
 * Example 2:
 * Input: words = ["z","x"]
 * Output: "zx"
 *
 * Example 3:
 * Input: words = ["z","x","z"]
 * Output: ""
 * Explanation: The order is invalid, so return "".
 *
 * Constraints:
 * - 1 <= words.length <= 100
 * - 1 <= words[i].length <= 100
 * - words[i] consists of only lowercase English letters.
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#define vvi vector<vector<int>>
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        // need a queue for pushing the nodes whose indegree are 0 as they can be ahead of other nodes 
        queue<int> q;
        int n= words.size();
        // also need to make an adjacency list 
        // that is there is a connection b/w the nodes 
        // Calculate in-degree(how many ingoing edges are there to a particular node )
        // Now using topo sort (using kahn's algorithm)

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<string> words1 = {"wrt", "wrf", "er", "ett", "rftt"};
    cout << "Test 1: " << sol.alienOrder(words1) << endl;
    // Expected: "wertf" (or any valid ordering)

    // Test case 2
    vector<string> words2 = {"z", "x"};
    cout << "Test 2: " << sol.alienOrder(words2) << endl;
    // Expected: "zx"

    // Test case 3
    vector<string> words3 = {"z", "x", "z"};
    cout << "Test 3: \"" << sol.alienOrder(words3) << "\"" << endl;
    // Expected: ""

    return 0;
}
