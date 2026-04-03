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
    ListNode* swapPairs(ListNode* head) {
        // If the list is empty or has only one node, no swaps are possible
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            // Nodes to be swapped
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Swapping logic
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev pointer forward for the next pair
            prev = first;
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Clean up memory
        return newHead;
    }
};