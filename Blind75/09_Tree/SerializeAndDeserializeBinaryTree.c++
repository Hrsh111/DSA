/*
 * LeetCode #297 - Serialize and Deserialize Binary Tree
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in the
 * same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 *
 * Clarification: The input/output format is the same as how LeetCode serializes
 * a binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 *
 * Example 1:
 * Input: root = [1,2,3,null,null,4,5]
 * Output: [1,2,3,null,null,4,5]
 *
 * Example 2:
 * Input: root = []
 * Output: []
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 10^4].
 * - -1000 <= Node.val <= 1000
 */

#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // TODO: Implement your solution here

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // TODO: Implement your solution here

    }
};

// Helper function to print tree (level order)
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
    Codec codec;

    // Test case 1: [1,2,3,null,null,4,5]
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(5);
    string serialized1 = codec.serialize(root1);
    cout << "Serialized 1: " << serialized1 << endl;
    TreeNode* deserialized1 = codec.deserialize(serialized1);
    cout << "Test 1: ";
    printTree(deserialized1);
    // Expected: [1,2,3,null,null,4,5]

    // Test case 2: empty tree
    string serialized2 = codec.serialize(nullptr);
    cout << "Serialized 2: " << serialized2 << endl;
    TreeNode* deserialized2 = codec.deserialize(serialized2);
    cout << "Test 2: ";
    printTree(deserialized2);
    // Expected: []

    return 0;
}
