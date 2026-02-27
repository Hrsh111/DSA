/*
 * LeetCode #235 - Lowest Common Ancestor of a Binary Search Tree
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) node
 * of two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: "The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself)."
 *
 * Example 1:
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 *
 * Example 2:
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of
 * itself according to the LCA definition.
 *
 * Example 3:
 * Input: root = [2,1], p = 2, q = 1
 * Output: 2
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [2, 10^5].
 * - -10^9 <= Node.val <= 10^9
 * - All Node.val are unique.
 * - p != q
 * - p and q will exist in the BST.
 */

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1: [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    TreeNode* root1 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node8 = new TreeNode(8);
    root1->left = node2;
    root1->right = node8;
    node2->left = new TreeNode(0);
    node2->right = new TreeNode(4);
    node2->right->left = new TreeNode(3);
    node2->right->right = new TreeNode(5);
    node8->left = new TreeNode(7);
    node8->right = new TreeNode(9);
    cout << "Test 1: " << sol.lowestCommonAncestor(root1, node2, node8)->val << endl;
    // Expected: 6

    // Test case 2: p = 2, q = 4
    TreeNode* node4 = node2->right;
    cout << "Test 2: " << sol.lowestCommonAncestor(root1, node2, node4)->val << endl;
    // Expected: 2

    return 0;
}
