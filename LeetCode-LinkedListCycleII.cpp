#include "Debug.cpp"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !(head->next)) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;      

        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        if (fast != slow) return nullptr;

        slow = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};