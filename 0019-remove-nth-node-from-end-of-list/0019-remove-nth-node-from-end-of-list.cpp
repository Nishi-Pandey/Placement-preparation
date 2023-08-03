/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* first = &dummy;
        ListNode* second = &dummy;

        // Move the second pointer n steps ahead
        for (int i = 0; i <= n; ++i) {
            second = second->next;
        }

        // Move both pointers simultaneously until the second pointer reaches the end
        while (second) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node from the end
        ListNode* temp = first->next;
        first->next = first->next->next;
        delete temp;

        return dummy.next;
    }
};