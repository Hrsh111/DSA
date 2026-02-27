/*
 * LeetCode #100 - Same Tree
 * https://leetcode.com/problems/same-tree/
 *
 * Given the roots of two binary trees p and q, write a function to check if they
 * are the same or not.
 *
 * Two binary trees are considered the same if they are structurally identical,
 * and the nodes have the same value.
 *
 * Example 1:
 * Input: p = [1,2,3], q = [1,2,3]
 * Output: true
 *
 * Example 2:
 * Input: p = [1,2], q = [1,null,2]
 * Output: false
 *
 * Example 3:
 * Input: p = [1,2,1], q = [1,1,2]
 * Output: false
 *
 * Constraints:
 * - The number of nodes in both trees is in the range [0, 100].
 * - -10^4 <= Node.val <= 10^4
 */

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1: p = [1,2,3], q = [1,2,3]
    TreeNode* p1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << "Test 1: " << (sol.isSameTree(p1, q1) ? "true" : "false") << endl;
    // Expected: true

    // Test case 2: p = [1,2], q = [1,null,2]
    TreeNode* p2 = new TreeNode(1);
    p2->left = new TreeNode(2);
    TreeNode* q2 = new TreeNode(1);
    q2->right = new TreeNode(2);
    cout << "Test 2: " << (sol.isSameTree(p2, q2) ? "true" : "false") << endl;
    // Expected: false

    // Test case 3: p = [1,2,1], q = [1,1,2]
    TreeNode* p3 = new TreeNode(1, new TreeNode(2), new TreeNode(1));
    TreeNode* q3 = new TreeNode(1, new TreeNode(1), new TreeNode(2));
    cout << "Test 3: " << (sol.isSameTree(p3, q3) ? "true" : "false") << endl;
    // Expected: false

    return 0;
}
