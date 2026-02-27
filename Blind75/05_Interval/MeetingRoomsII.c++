/*
 * LeetCode #253 - Meeting Rooms II (Premium)
 * https://leetcode.com/problems/meeting-rooms-ii/
 *
 * Given an array of meeting time intervals intervals where
 * intervals[i] = [starti, endi], return the minimum number of conference rooms
 * required.
 *
 * Example 1:
 * Input: intervals = [[0,30],[5,10],[15,20]]
 * Output: 2
 *
 * Example 2:
 * Input: intervals = [[7,10],[2,4]]
 * Output: 1
 *
 * Constraints:
 * - 1 <= intervals.length <= 10^4
 * - 0 <= starti < endi <= 10^6
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    cout << "Test 1: " << sol.minMeetingRooms(intervals1) << endl;
    // Expected: 2

    // Test case 2
    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    cout << "Test 2: " << sol.minMeetingRooms(intervals2) << endl;
    // Expected: 1

    // Test case 3
    vector<vector<int>> intervals3 = {{1, 5}, {2, 6}, {3, 7}};
    cout << "Test 3: " << sol.minMeetingRooms(intervals3) << endl;
    // Expected: 3

    return 0;
}
