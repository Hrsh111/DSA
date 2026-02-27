/*
 * LeetCode #98 - Validate Binary Search Tree
 * https://leetcode.com/problems/validate-binary-search-tree/
 *
 * Given the root of a binary tree, determine if it is a valid binary search tree
 * (BST).
 *
 * A valid BST is defined as follows:
 * - The left subtree of a node contains only nodes with keys less than the node's key.
 * - The right subtree of a node contains only nodes with keys greater than the node's key.
 * - Both the left and right subtrees must also be binary search trees.
 *
 * Example 1:
 * Input: root = [2,1,3]
 * Output: true
 *
 * Example 2:
 * Input: root = [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [1, 10^4].
 * - -2^31 <= Node.val <= 2^31 - 1
 */

#include <iostream>
#include <climits>
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
    bool isValidBST(TreeNode* root) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1: [2,1,3]
    TreeNode* root1 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    cout << "Test 1: " << (sol.isValidBST(root1) ? "true" : "false") << endl;
    // Expected: true

    // Test case 2: [5,1,4,null,null,3,6]
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4, new TreeNode(3), new TreeNode(6));
    cout << "Test 2: " << (sol.isValidBST(root2) ? "true" : "false") << endl;
    // Expected: false

    // Test case 3: [5,4,6,null,null,3,7]
    TreeNode* root3 = new TreeNode(5);
    root3->left = new TreeNode(4);
    root3->right = new TreeNode(6, new TreeNode(3), new TreeNode(7));
    cout << "Test 3: " << (sol.isValidBST(root3) ? "true" : "false") << endl;
    // Expected: false

    return 0;
}
