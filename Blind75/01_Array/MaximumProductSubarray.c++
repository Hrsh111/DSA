/*
 * LeetCode #152 - Maximum Product Subarray
 * https://leetcode.com/problems/maximum-product-subarray/
 *
 * Given an integer array nums, find a subarray that has the largest product,
 * and return the product.
 * The test cases are generated so that the answer will fit in a 32-bit integer.
 *
 * Example 1:
 * Input: nums = [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 *
 * Example 2:
 * Input: nums = [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 *
 * Constraints:
 * - 1 <= nums.length <= 2 * 10^4
 * - -10 <= nums[i] <= 10
 * - The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Test 1: " << sol.maxProduct(nums1) << endl;
    // Expected: 6

    // Test case 2
    vector<int> nums2 = {-2, 0, -1};
    cout << "Test 2: " << sol.maxProduct(nums2) << endl;
    // Expected: 0

    // Test case 3
    vector<int> nums3 = {-2, 3, -4};
    cout << "Test 3: " << sol.maxProduct(nums3) << endl;
    // Expected: 24

    return 0;
}
