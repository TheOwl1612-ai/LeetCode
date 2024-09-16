#include "Debug.cpp"

class Solution {
public:
    
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        while (temp){
            st.push(temp);
            temp = temp->next;
        }

        temp = head;
        while (temp != st.top() && st.top() -> next != temp){
            st.top()->next = temp->next;
            temp->next = st.top();
            temp = st.top()->next;
            st.pop();
        }
        temp -> next = nullptr;
    }
};

int main(){
    Solution solution;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    print(head);
    solution.reorderList(head);
    deleteList(head);
}