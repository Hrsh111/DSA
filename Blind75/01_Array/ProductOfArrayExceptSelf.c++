/*
 * LeetCode #238 - Product of Array Except Self
 * https://leetcode.com/problems/product-of-array-except-self/
 *
 * Given an integer array nums, return an array answer such that answer[i] is
 * equal to the product of all the elements of nums except nums[i].
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 *
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 *
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 *
 * Constraints:
 * - 2 <= nums.length <= 10^5
 * - -30 <= nums[i] <= 30
 * - The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 *
 * Follow up: Can you solve the problem in O(1) extra space complexity?
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // TODO: Implement your solution here
        int n =nums.size();
        vector<int> res(n,1);
        int prefix = 1;
        for(int i=0;i<n;i++){
            prefix*=res[i];
            
        }
        return res;

    }
};

// Helper function to print vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Test 1: ";
    printVector(sol.productExceptSelf(nums1));
    // Expected: [24, 12, 8, 6]

    // Test case 2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    cout << "Test 2: ";
    printVector(sol.productExceptSelf(nums2));
    // Expected: [0, 0, 9, 0, 0]

    return 0;
}
