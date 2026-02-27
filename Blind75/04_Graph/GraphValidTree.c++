/*
 * LeetCode rgb(102, 17, 17) - Graph Valid Tree (Premium)
 * https://leetcode.com/problems/graph-valid-tree/
 *
 * You have a graph of n nodes labeled from 0 to n - 1. You are given an integer
 * n and a list of edges where edges[i] = [ai, bi] indicates that there is an
 * undirected edge between nodes ai and bi in the graph.
 *
 * Return true if the edges of the given graph make up a valid tree, and false
 * otherwise.
 *
 * A valid tree must satisfy these conditions:
 * 1. The graph must be fully connected (all nodes reachable from any node)
 * 2. The graph must have no cycles
 * 3. The number of edges must be exactly n - 1
 *
 * Example 1:
 * Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
 * Output: true
 *
 * Example 2:
 * Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
 * Output: false
 * 
 *
 *
 * Constraints:
 * - 1 <= n <= 2000
 * - 0 <= edges.length <= 5000
 * - edges[i].length == 2
 * - 0 <= ai, bi < n
 * - ai != bi
 * - There are no self-loops or repeated edges.
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    cout << "Test 1: " << (sol.validTree(5, edges1) ? "true" : "false") << endl;
    // Expected: true

    // Test case 2
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    cout << "Test 2: " << (sol.validTree(5, edges2) ? "true" : "false") << endl;
    // Expected: false

    // Test case 3
    vector<vector<int>> edges3 = {};
    cout << "Test 3: " << (sol.validTree(1, edges3) ? "true" : "false") << endl;
    // Expected: true

    return 0;
}
