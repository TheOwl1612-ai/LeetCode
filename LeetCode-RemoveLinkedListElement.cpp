#include <iostream>
#include <memory>
#include "Debug.cpp"


 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head -> val == val)
            head = head -> next;
        ListNode* curr = head;
        while (curr != nullptr && curr -> next != nullptr){
            if (curr -> next -> val == val)
                curr -> next = curr->next->next;
            else
                curr = curr->next;
        }
        return head;
    }
};

int main(){
    Solution solution;
    ListNode* head = new ListNode(6);
    ListNode* head2 = new ListNode(6);
    ListNode* head3 = new ListNode(6);
    ListNode* head4 = new ListNode(6);
    ListNode* head5 = new ListNode(6);
    ListNode* head6 = new ListNode(6);
    ListNode* head7 = new ListNode(6);
    head -> next = head2;
    head2 -> next = head3;
    head3 -> next = head4;
    head4 -> next = head5;
    head5 -> next = head6;
    head6 -> next = head7;

    ListNode* res = solution.removeElements(head,6);
    print(res);
}