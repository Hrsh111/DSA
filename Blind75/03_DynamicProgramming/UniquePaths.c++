/*
 * LeetCode #62 - Unique Paths
 * https://leetcode.com/problems/unique-paths/
 *
 * There is a robot on an m x n grid. The robot is initially located at the
 * top-left corner (i.e., grid[0][0]). The robot tries to move to the
 * bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either
 * down or right at any point in time.
 *
 * Given the two integers m and n, return the number of possible unique paths
 * that the robot can take to reach the bottom-right corner.
 *
 * Example 1:
 * Input: m = 3, n = 7
 * Output: 28
 *
 * Example 2:
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation: From the top-left corner, there are a total of 3 ways to reach
 * the bottom-right corner:
 * 1. Right -> Down -> Down
 * 2. Down -> Down -> Right
 * 3. Down -> Right -> Down
 *
 * Constraints:
 * - 1 <= m, n <= 100
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    cout << "Test 1: " << sol.uniquePaths(3, 7) << endl;
    // Expected: 28

    // Test case 2
    cout << "Test 2: " << sol.uniquePaths(3, 2) << endl;
    // Expected: 3

    // Test case 3
    cout << "Test 3: " << sol.uniquePaths(7, 3) << endl;
    // Expected: 28

    return 0;
}
