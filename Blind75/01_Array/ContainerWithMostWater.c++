/*
 * LeetCode #11 - Container With Most Water
 * https://leetcode.com/problems/container-with-most-water/
 *
 * You are given an integer array height of length n. There are n vertical lines
 * drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
 * Find two lines that together with the x-axis form a container, such that the
 * container contains the most water.
 * Return the maximum amount of water a container can store.
 * Notice that you may not slant the container.
 *
 * Example 1:
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 *
 *   8 |    |              |
 *   7 |    |~~~~~~~~~~~~~ | ~~~|
 *   6 |    |  |~~~~~~~~~~~ | ~~|
 *   5 |    |  |     |~~~~~ | ~~|
 *   4 |    |  |     |  |~~ | ~~|
 *   3 |    |  |     |  |  | |  |
 *   2 |    |  |  |  |  |  | |  |
 *   1 | |  |  |  |  |  |  | |  |
 *     +--+--+--+--+--+--+--+--+--
 *       1  8  6  2  5  4  8  3  7
 *      [0][1][2][3][4][5][6][7][8]
 *
 *   The max area is between index 1 (height=8) and index 8 (height=7):
 *   area = min(8, 7) * (8 - 1) = 7 * 7 = 49
 *
 * Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
 * In this case, the max area of water (~ section) the container can contain is 49.
 *
 * Example 2:
 * Input: height = [1,1]
 * Output: 1
 *
 * Constraints:
 * - n == height.length
 * - 2 <= n <= 10^5
 * - 0 <= height[i] <= 10^4
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // TODO: Implement your solution here
        // Using two pointers approach 
        int n=height.size();
        int left=0 , right =n-1;
        int area, maxA=0;
      while(left<right){
         area= min(height[left], height[right])*(right-left);
             maxA=max(area,maxA);
        if (height[left]>height[right]){
            right--;
        }
        else left++;
      }
      return maxA;
        

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test 1: " << sol.maxArea(height1) << endl;
    // Expected: 49

    // Test case 2
    vector<int> height2 = {1, 1};
    cout << "Test 2: " << sol.maxArea(height2) << endl;
    // Expected: 1

    // Test case 3
    vector<int> height3 = {4, 3, 2, 1, 4};
    cout << "Test 3: " << sol.maxArea(height3) << endl;
    // Expected: 16

    return 0;
}
