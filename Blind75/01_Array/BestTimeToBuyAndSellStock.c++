/*
 * LeetCode #121 - Best Time to Buy and Sell Stock
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the ith day. You want to maximize your profit by choosing a single day to
 * buy one stock and choosing a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you
 * cannot achieve any profit, return 0.
 *
 * Example 1:
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 *
 * Example 2:
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit = 0.
 *
 * Constraints:
 * - 1 <= prices.length <= 10^5
 * - 0 <= prices[i] <= 10^4
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Test 1: " << sol.maxProfit(prices1) << endl;
    // Expected: 5

    // Test case 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Test 2: " << sol.maxProfit(prices2) << endl;
    // Expected: 0

    // Test case 3
    vector<int> prices3 = {2, 4, 1};
    cout << "Test 3: " << sol.maxProfit(prices3) << endl;
    // Expected: 2

    return 0;
}
