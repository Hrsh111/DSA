/*
 * LeetCode #323 - Number of Connected Components in an Undirected Graph (Premium)
 * https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
 *
 * You have a graph of n nodes. You are given an integer n and an array edges
 * where edges[i] = [ai, bi] indicates that there is an edge between ai and bi
 * in the graph.
 *
 * Return the number of connected components in the graph.
 *
 * Example 1:
 * Input: n = 5, edges = [[0,1],[1,2],[3,4]]
 * Output: 2
 *
 * Example 2:
 * Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
 * Output: 1
 *
 * Constraints:
 * - 1 <= n <= 2000
 * - 1 <= edges.length <= 5000
 * - edges[i].length == 2
 * - 0 <= ai, bi < n
 * - ai != bi
 * - There are no repeated edges.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {3, 4}};
    cout << "Test 1: " << sol.countComponents(5, edges1) << endl;
    // Expected: 2

    // Test case 2
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    cout << "Test 2: " << sol.countComponents(5, edges2) << endl;
    // Expected: 1

    // Test case 3
    vector<vector<int>> edges3 = {};
    cout << "Test 3: " << sol.countComponents(3, edges3) << endl;
    // Expected: 3

    return 0;
}
