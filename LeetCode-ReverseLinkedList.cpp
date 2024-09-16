#include "Debug.cpp"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = head;
        while (next){
            head = next;
            next = head -> next;
            head->next = prev;
            prev = head;
        }
        return head;
    }
};

int main(){
    ListNode* head1 = new ListNode(1);
    ListNode* head2 = new ListNode(2);
    ListNode* head3 = new ListNode(3);
    ListNode* head4 = new ListNode(4);
    ListNode* head5 = new ListNode(5);
    head1 -> next = head2;
    head2 -> next = head3;
    head3 -> next = head4;
    head4 -> next = head5;
    Solution solution;
    ListNode* res = solution.reverseList(head1);
    print(res);
    deleteList(res);
    deleteList(head1);

}