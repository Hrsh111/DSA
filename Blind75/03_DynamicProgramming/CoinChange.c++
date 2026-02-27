/*
 * LeetCode #322 - Coin Change
 * https://leetcode.com/problems/coin-change/
 *
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 * Return the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins,
 * return -1.
 * You may assume that you have an infinite number of each kind of coin.
 *
 * Example 1:
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 * Example 2:
 * Input: coins = [2], amount = 3
 * Output: -1
 *
 * Example 3:
 * Input: coins = [1], amount = 0
 * Output: 0
 *
 * Constraints:
 * - 1 <= coins.length <= 12
 * - 1 <= coins[i] <= 2^31 - 1
 * - 0 <= amount <= 10^4
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<int> coins1 = {1, 2, 5};
    cout << "Test 1: " << sol.coinChange(coins1, 11) << endl;
    // Expected: 3

    // Test case 2
    vector<int> coins2 = {2};
    cout << "Test 2: " << sol.coinChange(coins2, 3) << endl;
    // Expected: -1

    // Test case 3
    vector<int> coins3 = {1};
    cout << "Test 3: " << sol.coinChange(coins3, 0) << endl;
    // Expected: 0

    return 0;
}
