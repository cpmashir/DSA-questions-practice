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
        if (!head || !head->next || k == 0) return head;

        ListNode* curr = head;
        int len = 1;
        while (curr->next) {
            curr = curr->next;
            len++;
        }

        k %= len;
        if (k == 0) return head;

        curr->next = head;
        int stepsToNewTail = len - k;
        
        while (stepsToNewTail--) {
            curr = curr->next;
        }

        head = curr->next;
        curr->next = nullptr;

        return head;
    }
};