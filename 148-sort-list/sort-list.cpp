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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Count the length of the linked list
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }

        ListNode dummy(0);
        dummy.next = head;

        // Bottom-up merge sort: step doubles each iteration (1, 2, 4, 8...)
        for (int step = 1; step < length; step <<= 1) {
            ListNode* prev = &dummy;
            curr = dummy.next;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, step);
                curr = split(right, step); // Next starting point for the next pair
                prev = merge(left, right, prev);
            }
        }

        return dummy.next;
    }

private:
    // Splits the list into two parts: first 'n' nodes and the rest.
    // Returns the head of the second part.
    ListNode* split(ListNode* head, int n) {
        for (int i = 1; head && i < n; i++) head = head->next;
        
        if (!head) return nullptr;
        ListNode* second = head->next;
        head->next = nullptr; // Cut the connection
        return second;
    }

    // Merges two sorted lists and attaches the result to 'prev'.
    // Returns the tail of the merged list.
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* prev) {
        ListNode* curr = prev;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        while (curr->next) curr = curr->next; // Move to the end of the merged list
        return curr;
    }
};