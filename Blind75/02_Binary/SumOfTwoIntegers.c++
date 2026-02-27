/*
 * LeetCode #371 - Sum of Two Integers
 * https://leetcode.com/problems/sum-of-two-integers/
 *
 * Given two integers a and b, return the sum of the two integers without using
 * the operators + and -.
 *
 * Example 1:
 * Input: a = 1, b = 2
 * Output: 3
 *
 * Example 2:
 * Input: a = 2, b = 3
 * Output: 5
 *
 * Constraints:
 * - -1000 <= a, b <= 1000
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    cout << "Test 1: " << sol.getSum(1, 2) << endl;
    // Expected: 3

    // Test case 2
    cout << "Test 2: " << sol.getSum(2, 3) << endl;
    // Expected: 5

    // Test case 3
    cout << "Test 3: " << sol.getSum(-1, 1) << endl;
    // Expected: 0

    return 0;
}
