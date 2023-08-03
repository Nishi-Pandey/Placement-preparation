/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* meetingPoint = nullptr;

        // Find the meeting point (if cycle exists) using the tortoise and hare algorithm.
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                meetingPoint = slow;
                break;
            }
        }

        // If there is no cycle, return null.
        if (!meetingPoint) {
            return nullptr;
        }

        // Move one of the pointers back to the head.
        // Keep the other pointer at the meeting point.
        // Then move both pointers one step at a time until they meet at the cycle start node.
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Both pointers now point to the cycle start node.
        return slow;
    }
};