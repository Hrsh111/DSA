/*
 * LeetCode #230 - Kth Smallest Element in a BST
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 *
 * Given the root of a binary search tree, and an integer k, return the kth
 * smallest value (1-indexed) of all the values of the nodes in the tree.
 *
 * Example 1:
 * Input: root = [3,1,4,null,2], k = 1
 * Output: 1
 *
 * Example 2:
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * Output: 3
 *
 * Constraints:
 * - The number of nodes in the tree is n.
 * - 1 <= k <= n <= 10^4
 * - 0 <= Node.val <= 10^4
 *
 * Follow up: If the BST is modified often (i.e., we can do insert and delete
 * operations) and you need to find the kth smallest frequently, how would you
 * optimize?
 */

#include <iostream>
#include <stack>
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
    int kthSmallest(TreeNode* root, int k) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1: [3,1,4,null,2], k = 1
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->left->right = new TreeNode(2);
    root1->right = new TreeNode(4);
    cout << "Test 1: " << sol.kthSmallest(root1, 1) << endl;
    // Expected: 1

    // Test case 2: [5,3,6,2,4,null,null,1], k = 3
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->left->left = new TreeNode(2);
    root2->left->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(4);
    root2->right = new TreeNode(6);
    cout << "Test 2: " << sol.kthSmallest(root2, 3) << endl;
    // Expected: 3

    return 0;
}
