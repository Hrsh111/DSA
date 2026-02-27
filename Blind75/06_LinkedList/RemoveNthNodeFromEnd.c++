/*
 * LeetCode #19 - Remove Nth Node From End of List
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * Given the head of a linked list, remove the nth node from the end of the list
 * and return its head.
 *
 * Example 1:
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 * Example 2:
 * Input: head = [1], n = 1
 * Output: []
 *
 * Example 3:
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 * Constraints:
 * - The number of nodes in the list is sz.
 * - 1 <= sz <= 30
 * - 0 <= Node.val <= 100
 * - 1 <= n <= sz
 *
 * Follow up: Could you do this in one pass?
 */

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // TODO: Implement your solution here

    }
};

// Helper function to create linked list from vector
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]" << endl;
}

// Test cases
int main() {
    Solution sol;

    // Test case 1
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    cout << "Test 1: ";
    printList(sol.removeNthFromEnd(head1, 2));
    // Expected: [1,2,3,5]

    // Test case 2
    ListNode* head2 = createList({1});
    cout << "Test 2: ";
    printList(sol.removeNthFromEnd(head2, 1));
    // Expected: []

    // Test case 3
    ListNode* head3 = createList({1, 2});
    cout << "Test 3: ";
    printList(sol.removeNthFromEnd(head3, 1));
    // Expected: [1]

    return 0;
}
