/*
 * LeetCode #338 - Counting Bits
 * https://leetcode.com/problems/counting-bits/
 *
 * Given an integer n, return an array ans of length n + 1 such that for each i
 * (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
 *
 * Example 1:
 * Input: n = 2
 * Output: [0,1,1]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 *
 * Example 2:
 * Input: n = 5
 * Output: [0,1,1,2,1,2]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 * 3 --> 11
 * 4 --> 100
 * 5 --> 101
 *
 * Constraints:
 * - 0 <= n <= 10^5
 *
 * Follow up:
 * - It is very easy to come up with a solution with a runtime of O(n log n).
 *   Can you do it in linear time O(n) and possibly in a single pass?
 * - Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        // TODO: Implement your solution here

    }
};

// Helper function to print vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// Test cases
int main() {
    Solution sol;

    // Test case 1
    cout << "Test 1: ";
    printVector(sol.countBits(2));
    // Expected: [0,1,1]

    // Test case 2
    cout << "Test 2: ";
    printVector(sol.countBits(5));
    // Expected: [0,1,1,2,1,2]

    return 0;
}
