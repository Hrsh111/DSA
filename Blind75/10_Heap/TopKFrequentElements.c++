/*
 * LeetCode #347 - Top K Frequent Elements
 * https://leetcode.com/problems/top-k-frequent-elements/
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 *
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 *
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * - -10^4 <= nums[i] <= 10^4
 * - k is in the range [1, the number of unique elements in the array].
 * - It is guaranteed that the answer is unique.
 *
 * Follow up: Your algorithm's time complexity must be better than O(n log n),
 * where n is the array's size.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // TODO: Implement your solution here
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }
      
        // making a bucket and filling the frquencies along with the number 
        vector<vector<int>> buckets(nums.size());
        // using a iterator approach for accessing the elements of the pair 
        for(auto &p : freq){
            buckets[p.second].push_back(p.first);
        }
        // now we have the elements in the bucket Sorting the buckets now 
        


        vector<int> res;
        // iterate from the end of the bucket to get the most frequent elements
        for(int i=buckets.size()-1;i>=0;i++){
            
        }


        
       

    }
};

// Helper function to print vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    cout << "Test 1: ";
    printVector(sol.topKFrequent(nums1, 2));
    // Expected: [1,2] (order may vary)

    // Test case 2
    vector<int> nums2 = {1};
    cout << "Test 2: ";
    printVector(sol.topKFrequent(nums2, 1));
    // Expected: [1]

    // Test case 3
    vector<int> nums3 = {1, 2, 2, 3, 3, 3};
    cout << "Test 3: ";
    printVector(sol.topKFrequent(nums3, 2));
    // Expected: [3,2] (order may vary)

    return 0;
}
