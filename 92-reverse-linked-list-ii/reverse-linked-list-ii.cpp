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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Dummy node to simplify edge cases where left = 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // 1. Move 'prev' to the node at position (left - 1)
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        // 'curr' is the node at position 'left'
        ListNode* curr = prev->next;

        // 2. Perform the reversal between left and right
        // We repeat the operation (right - left) times
        for (int i = 0; i < right - left; ++i) {
            ListNode* temp = curr->next;      // The node to be moved
            curr->next = temp->next;          // Link curr to the node after temp
            temp->next = prev->next;          // Link temp to the current start of sub-list
            prev->next = temp;                // Move temp to the front of sub-list
        }

        return dummy->next;
    }
};