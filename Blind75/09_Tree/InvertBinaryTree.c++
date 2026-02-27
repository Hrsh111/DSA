/*
 * LeetCode #226 - Invert Binary Tree
 * https://leetcode.com/problems/invert-binary-tree/
 *
 * Given the root of a binary tree, invert the tree, and return its root.
 *
 * Example 1:
 * Input: root = [4,2,7,1,3,6,9]
 * Output: [4,7,2,9,6,3,1]
 *
 * Example 2:
 * Input: root = [2,1,3]
 * Output: [2,3,1]
 *
 * Example 3:
 * Input: root = []
 * Output: []
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 100].
 * - -100 <= Node.val <= 100
 */

#include <iostream>
#include <queue>
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
    TreeNode* invertTree(TreeNode* root) {
        // TODO: Implement your solution here

    }
};

// Helper function to print tree level order
void printTree(TreeNode* root) {
    if (!root) {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    queue<TreeNode*> q;
    q.push(root);
    bool first = true;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (!first) cout << ",";
        first = false;
        if (node) {
            cout << node->val;
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null";
        }
    }
    cout << "]" << endl;
}

// Test cases
int main() {
    Solution sol;

    // Test case 1: [4,2,7,1,3,6,9]
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    root1->right = new TreeNode(7, new TreeNode(6), new TreeNode(9));
    cout << "Test 1: ";
    printTree(sol.invertTree(root1));
    // Expected: [4,7,2,9,6,3,1]

    // Test case 2: [2,1,3]
    TreeNode* root2 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    cout << "Test 2: ";
    printTree(sol.invertTree(root2));
    // Expected: [2,3,1]

    // Test case 3: empty tree
    cout << "Test 3: ";
    printTree(sol.invertTree(nullptr));
    // Expected: []

    return 0;
}
