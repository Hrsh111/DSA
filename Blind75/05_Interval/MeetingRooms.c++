/*
 * LeetCode #252 - Meeting Rooms (Premium)
 * https://leetcode.com/problems/meeting-rooms/
 *
 * Given an array of meeting time intervals where intervals[i] = [starti, endi],
 * determine if a person could attend all meetings.
 *
 * Example 1:
 * Input: intervals = [[0,30],[5,10],[15,20]]
 * Output: false
 *
 * Example 2:
 * Input: intervals = [[7,10],[2,4]]
 * Output: true
 *
 * Constraints:
 * - 0 <= intervals.length <= 10^4
 * - intervals[i].length == 2
 * - 0 <= starti < endi <= 10^6
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    cout << "Test 1: " << (sol.canAttendMeetings(intervals1) ? "true" : "false") << endl;
    // Expected: false

    // Test case 2
    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    cout << "Test 2: " << (sol.canAttendMeetings(intervals2) ? "true" : "false") << endl;
    // Expected: true

    // Test case 3
    vector<vector<int>> intervals3 = {};
    cout << "Test 3: " << (sol.canAttendMeetings(intervals3) ? "true" : "false") << endl;
    // Expected: true

    return 0;
}
