/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode *pA = headA;
        ListNode *pB = headB;

        // If pA and pB have different lengths, they will eventually meet 
        // after switching heads at most once.
        while (pA != pB) {
            // If pA reaches the end, redirect to headB. Otherwise, move to next.
            pA = (pA == nullptr) ? headB : pA->next;
            // If pB reaches the end, redirect to headA. Otherwise, move to next.
            pB = (pB == nullptr) ? headA : pB->next;
        }

        // Either they meet at the intersection node, or both are nullptr (no intersection).
        return pA;
    }
};