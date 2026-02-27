/*
 * LeetCode #55 - Jump Game
 * https://leetcode.com/problems/jump-game/
 *
 * You are given an integer array nums. You are initially positioned at the
 * array's first index, and each element in the array represents your maximum
 * jump length at that position.
 * Return true if you can reach the last index, or false otherwise.
 *
 * Example 1:
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *
 * Example 2:
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum jump
 * length is 0, which makes it impossible to reach the last index.
 *
 * Constraints:
 * - 1 <= nums.length <= 10^4
 * - 0 <= nums[i] <= 10^5
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test 1: " << (sol.canJump(nums1) ? "true" : "false") << endl;
    // Expected: true

    // Test case 2
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Test 2: " << (sol.canJump(nums2) ? "true" : "false") << endl;
    // Expected: false

    // Test case 3
    vector<int> nums3 = {0};
    cout << "Test 3: " << (sol.canJump(nums3) ? "true" : "false") << endl;
    // Expected: true

    return 0;
}
