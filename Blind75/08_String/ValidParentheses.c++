/*
 * LeetCode #20 - Valid Parentheses
 * https://leetcode.com/problems/valid-parentheses/
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 *
 * An input string is valid if:
 * 1. Open brackets must be closed by the same type of brackets.
 * 2. Open brackets must be closed in the correct order.
 * 3. Every close bracket has a corresponding open bracket of the same type.
 *
 * Example 1:
 * Input: s = "()"
 * Output: true
 *
 * Example 2:
 * Input: s = "()[]{}"
 * Output: true
 *
 * Example 3:
 * Input: s = "(]"
 * Output: false
 *
 * Constraints:
 * - 1 <= s.length <= 10^4
 * - s consists of parentheses only '()[]{}'.
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    cout << "Test 1: " << (sol.isValid("()") ? "true" : "false") << endl;
    // Expected: true

    // Test case 2
    cout << "Test 2: " << (sol.isValid("()[]{}") ? "true" : "false") << endl;
    // Expected: true

    // Test case 3
    cout << "Test 3: " << (sol.isValid("(]") ? "true" : "false") << endl;
    // Expected: false

    // Test case 4
    cout << "Test 4: " << (sol.isValid("([)]") ? "true" : "false") << endl;
    // Expected: false

    // Test case 5
    cout << "Test 5: " << (sol.isValid("{[]}") ? "true" : "false") << endl;
    // Expected: true

    return 0;
}
