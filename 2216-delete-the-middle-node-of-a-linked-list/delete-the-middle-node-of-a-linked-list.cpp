/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// Fast I/O block that executes before the main function runs
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Base case: 1 node
        if (!head || !head->next) {
            return nullptr; 
        }

        // If there are exactly 2 nodes, middle is head->next
        if (!head->next->next) {
            head->next = nullptr;
            return head;
        }

        // Two pointer approach optimized to stay one step behind the middle
        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is now pointing to the node BEFORE the middle node
        // Skip the middle node entirely
        slow->next = slow->next->next;

        return head;
    }
};