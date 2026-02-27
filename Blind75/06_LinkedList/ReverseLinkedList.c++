/*
 * LeetCode #206 - Reverse Linked List
 * https://leetcode.com/problems/reverse-linked-list/
 *
 * Given the head of a singly linked list, reverse the list, and return the
 * reversed list.
 *
 * Example 1:
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 *
 * Example 2:
 * Input: head = [1,2]
 * Output: [2,1]
 *
 * Example 3:
 * Input: head = []
 * Output: []
 *
 * Constraints:
 * - The number of nodes in the list is the range [0, 5000].
 * - -5000 <= Node.val <= 5000
 *
 * Follow up: A linked list can be reversed either iteratively or recursively.
 * Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
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
    printList(sol.reverseList(head1));
    // Expected: [5,4,3,2,1]

    // Test case 2
    ListNode* head2 = createList({1, 2});
    cout << "Test 2: ";
    printList(sol.reverseList(head2));
    // Expected: [2,1]

    // Test case 3
    ListNode* head3 = createList({});
    cout << "Test 3: ";
    printList(sol.reverseList(head3));
    // Expected: []

    return 0;
}
