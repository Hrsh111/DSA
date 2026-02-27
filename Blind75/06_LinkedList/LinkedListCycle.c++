/*
 * LeetCode #141 - Linked List Cycle
 * https://leetcode.com/problems/linked-list-cycle/
 *
 * Given head, the head of a linked list, determine if the linked list has a
 * cycle in it.
 *
 * There is a cycle in a linked list if there is some node in the list that can
 * be reached again by continuously following the next pointer. Internally, pos
 * is used to denote the index of the node that tail's next pointer is connected
 * to. Note that pos is not passed as a parameter.
 *
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 *
 * Example 1:
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where the tail connects to
 * the 1st node (0-indexed).
 *
 * Example 2:
 * Input: head = [1,2], pos = 0
 * Output: true
 * Explanation: There is a cycle in the linked list, where the tail connects to
 * the 0th node.
 *
 * Example 3:
 * Input: head = [1], pos = -1
 * Output: false
 * Explanation: There is no cycle in the linked list.
 *
 * Constraints:
 * - The number of the nodes in the list is in the range [0, 10^4].
 * - -10^5 <= Node.val <= 10^5
 * - pos is -1 or a valid index in the linked-list.
 *
 * Follow up: Can you solve it using O(1) (i.e. constant) memory?
 */

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // TODO: Implement your solution here

    }
};

// Helper function to create linked list with cycle
ListNode* createListWithCycle(const vector<int>& values, int pos) {
    if (values.empty()) return nullptr;
    vector<ListNode*> nodes;
    for (int val : values) {
        nodes.push_back(new ListNode(val));
    }
    for (int i = 0; i < nodes.size() - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }
    if (pos >= 0) {
        nodes.back()->next = nodes[pos];
    }
    return nodes[0];
}

// Test cases
int main() {
    Solution sol;

    // Test case 1
    ListNode* head1 = createListWithCycle({3, 2, 0, -4}, 1);
    cout << "Test 1: " << (sol.hasCycle(head1) ? "true" : "false") << endl;
    // Expected: true

    // Test case 2
    ListNode* head2 = createListWithCycle({1, 2}, 0);
    cout << "Test 2: " << (sol.hasCycle(head2) ? "true" : "false") << endl;
    // Expected: true

    // Test case 3
    ListNode* head3 = createListWithCycle({1}, -1);
    cout << "Test 3: " << (sol.hasCycle(head3) ? "true" : "false") << endl;
    // Expected: false

    return 0;
}
