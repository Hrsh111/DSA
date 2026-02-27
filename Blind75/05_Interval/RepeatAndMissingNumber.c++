/*
 * Find the Repeating and Missing Number
 *
 * Given an unsorted array of size n. Array elements are in the range of 1 to n.
 * One number from set {1, 2, ...n} is missing and one number occurs twice in the
 * array. Find these two numbers.
 *
 * Example 1:
 * Input: arr = [3, 1, 3]
 * Output: {3, 2}
 * Explanation: 3 is repeating, 2 is missing
 *
 * Example 2:
 * Input: arr = [4, 3, 6, 2, 1, 1]
 * Output: {1, 5}
 * Explanation: 1 is repeating, 5 is missing
 *
 * Constraints:
 * - 2 <= n <= 10^5
 * - 1 <= arr[i] <= n
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        // TODO: Implement your solution here
        // Return {repeating, missing}

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<int> arr1 = {3, 1, 3};
    vector<int> result1 = sol.findTwoElement(arr1);
    cout << "Test 1: Repeating = " << result1[0] << ", Missing = " << result1[1] << endl;
    // Expected: Repeating = 3, Missing = 2

    // Test case 2
    vector<int> arr2 = {4, 3, 6, 2, 1, 1};
    vector<int> result2 = sol.findTwoElement(arr2);
    cout << "Test 2: Repeating = " << result2[0] << ", Missing = " << result2[1] << endl;
    // Expected: Repeating = 1, Missing = 5

    // Test case 3
    vector<int> arr3 = {2, 2};
    vector<int> result3 = sol.findTwoElement(arr3);
    cout << "Test 3: Repeating = " << result3[0] << ", Missing = " << result3[1] << endl;
    // Expected: Repeating = 2, Missing = 1

    return 0;
}
