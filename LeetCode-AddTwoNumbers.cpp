#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ~ListNode(){
        delete this;
    }

 };


void print(ListNode* head){
    while (head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


class Solution {
public:
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    int carry = 0;

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        while (l1 || l2 || carry != 0){
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;

            int sum = x+y+carry;
            carry = sum/10;
            curr->next = new ListNode(sum%10);

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            curr = curr->next;
        }
        return head->next;
    }
};

int main(){
    Solution solution;

    ListNode* num1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode* num2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

    ListNode* res = solution.addTwoNumbers(num1,num2);
    print(res);

}