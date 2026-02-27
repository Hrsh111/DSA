/*
 * LeetCode #217 - Contains Duplicate
 * https://leetcode.com/problems/contains-duplicate/
 *
 * Given an integer array nums, return true if any value appears at least twice
 * in the array, and return false if every element is distinct.
 *
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: true
 *
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: false
 *
 * Example 3:
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 *
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * - -10^9 <= nums[i] <= 10^9
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test 1: " << (sol.containsDuplicate(nums1) ? "true" : "false") << endl;
    // Expected: true

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Test 2: " << (sol.containsDuplicate(nums2) ? "true" : "false") << endl;
    // Expected: false

    // Test case 3
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << "Test 3: " << (sol.containsDuplicate(nums3) ? "true" : "false") << endl;
    // Expected: true

    return 0;
}
