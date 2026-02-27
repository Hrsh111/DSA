/*
 * LeetCode #191 - Number of 1 Bits
 * https://leetcode.com/problems/number-of-1-bits/
 *
 * Write a function that takes the binary representation of a positive integer
 * and returns the number of set bits it has (also known as the Hamming weight).
 *
 * Example 1:
 * Input: n = 11
 * Output: 3
 * Explanation: The input binary string 1011 has a total of three set bits.
 *
 * Example 2:
 * Input: n = 128
 * Output: 1
 * Explanation: The input binary string 10000000 has a total of one set bit.
 *
 * Example 3:
 * Input: n = 2147483645
 * Output: 30
 * Explanation: The input binary string 1111111111111111111111111111101 has a total of thirty set bits.
 *
 * Constraints:
 * - 1 <= n <= 2^31 - 1
 *
 * Follow up: If this function is called many times, how would you optimize it?
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    cout << "Test 1: " << sol.hammingWeight(11) << endl;
    // Expected: 3 (binary: 1011)

    // Test case 2
    cout << "Test 2: " << sol.hammingWeight(128) << endl;
    // Expected: 1 (binary: 10000000)

    // Test case 3
    cout << "Test 3: " << sol.hammingWeight(2147483645) << endl;
    // Expected: 30

    return 0;
}
