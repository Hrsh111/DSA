/*
 * LeetCode #572 - Subtree of Another Tree
 * https://leetcode.com/problems/subtree-of-another-tree/
 *
 * Given the roots of two binary trees root and subRoot, return true if there is
 * a subtree of root with the same structure and node values of subRoot and false
 * otherwise.
 *
 * A subtree of a binary tree tree is a tree that consists of a node in tree and
 * all of this node's descendants. The tree tree could also be considered as a
 * subtree of itself.
 *
 * Example 1:
 * Input: root = [3,4,5,1,2], subRoot = [4,1,2]
 * Output: true
 *
 * Example 2:
 * Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
 * Output: false
 *
 * Constraints:
 * - The number of nodes in the root tree is in the range [1, 2000].
 * - The number of nodes in the subRoot tree is in the range [1, 1000].
 * - -10^4 <= root.val <= 10^4
 * - -10^4 <= subRoot.val <= 10^4
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // TODO: Implement your solution here

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1: root = [3,4,5,1,2], subRoot = [4,1,2]
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    root1->right = new TreeNode(5);
    TreeNode* subRoot1 = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    cout << "Test 1: " << (sol.isSubtree(root1, subRoot1) ? "true" : "false") << endl;
    // Expected: true

    // Test case 2: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(4);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(2);
    root2->left->right->left = new TreeNode(0);
    root2->right = new TreeNode(5);
    TreeNode* subRoot2 = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    cout << "Test 2: " << (sol.isSubtree(root2, subRoot2) ? "true" : "false") << endl;
    // Expected: false

    return 0;
}
