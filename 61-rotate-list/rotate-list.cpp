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
    ListNode* rotateRight(ListNode* head, int k) {
        // 1. Edge cases: empty list, single node, or no rotation needed
        if (!head || !head->next || k == 0) {
            return head;
        }

        // 2. Compute the length of the list and find the last node
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // 3. Optimize k
        k = k % length;
        if (k == 0) return head;

        // 4. Connect tail to head to make it circular
        tail->next = head;

        // 5. Find the new tail: (length - k - 1) steps from the start
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }

        // 6. The node after newTail is the new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};