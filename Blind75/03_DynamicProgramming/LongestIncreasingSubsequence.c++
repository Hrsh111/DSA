/*
 * LeetCode #300 - Longest Increasing Subsequence
 * https://leetcode.com/problems/longest-increasing-subsequence/
 *
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 *
 * Example 1:
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
 * length is 4.
 *
 * Example 2:
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 *
 * Example 3:
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 *
 * Constraints:
 * - 1 <= nums.length <= 2500
 * - -10^4 <= nums[i] <= 10^4
 *
 * Follow up: Can you come up with an algorithm that runs in O(n log(n)) time
 * complexity?
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Test 1: " << sol.lengthOfLIS(nums1) << endl;
    // Expected: 4

    // Test case 2
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << "Test 2: " << sol.lengthOfLIS(nums2) << endl;
    // Expected: 4

    // Test case 3
    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    cout << "Test 3: " << sol.lengthOfLIS(nums3) << endl;
    // Expected: 1

    return 0;
}
