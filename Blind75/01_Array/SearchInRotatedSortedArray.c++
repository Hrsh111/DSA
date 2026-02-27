/*
 * LeetCode #33 - Search in Rotated Sorted Array
 * https://leetcode.com/problems/search-in-rotated-sorted-array/
 *
 * There is an integer array nums sorted in ascending order (with distinct values).
 * Prior to being passed to your function, nums is possibly rotated at an unknown
 * pivot index k (1 <= k < nums.length) such that the resulting array is
 * [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 *
 * Given the array nums after the possible rotation and an integer target, return
 * the index of target if it is in nums, or -1 if it is not in nums.
 * You must write an algorithm with O(log n) runtime complexity.
 *
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 *
 * Example 3:
 * Input: nums = [1], target = 0
 * Output: -1
 *
 * Constraints:
 * - 1 <= nums.length <= 5000
 * - -10^4 <= nums[i] <= 10^4
 * - All values of nums are unique.
 * - nums is an ascending array that is possibly rotated.
 * - -10^4 <= target <= 10^4
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test 1: " << sol.search(nums1, 0) << endl;
    // Expected: 4

    // Test case 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test 2: " << sol.search(nums2, 3) << endl;
    // Expected: -1

    // Test case 3
    vector<int> nums3 = {1};
    cout << "Test 3: " << sol.search(nums3, 0) << endl;
    // Expected: -1

    return 0;
}
