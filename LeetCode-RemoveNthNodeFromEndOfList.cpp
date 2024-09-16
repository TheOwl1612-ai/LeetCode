#include "Debug.cpp"

class Solution {
public:
    int count = 0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        /*Ý tưởng cơ bản: dùng hai con trỏ chậm và nhanh; nhanh - chậm = n
        Khi nhanh chạm tới cuối danh sách(nullptr) -> chậm ở vị trí n(so với cuối danh sách)
        -> Khi nhanh chạm tới nút trước cuối danh sách -> chậm ở vị trí n+1 (so với cuối danh sách)
        Từ đó nối nút ở chậm với nút n-1
        nếu n = độ dài danh sách thì trả về nút sau nút đầu*/
        for (int i = 0; i < n; i++)
            fast = fast->next;
        if (!fast) return head->next;
        while(fast->next) fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
    }
};

int main(){
    Solution solution;
    ListNode* head = new ListNode(1, new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    solution.removeNthFromEnd(head,2);
    deleteList(head);
}