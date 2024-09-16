#include "Debug.cpp"

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        size_t n = getSize(head);
        head = splitAndPush(head,n%k,n/k + 1); //processes big parts first
        head = splitAndPush(head,n-n%k,n/k); //processes small parts

        //if splitting not completed then add nullptr
        while (res.size() != k){
            res.push_back(nullptr);
        }
        return res;
            
    }
private:
    vector<ListNode*> res {};
    size_t getSize(ListNode* head){
        size_t n = 0;
        while (head){
            n++;
            head = head->next;
        }
        return n;
    }

    ListNode* splitAndPush(ListNode* head, int partsAmount, size_t partSize){
        while (partsAmount > 0 && head){
            ListNode* temp = head;
            size_t curSize = 0;
            while (temp && curSize < partSize - 1){
                curSize++;
                temp = temp->next;
            }
            ListNode* nextHead = temp->next;
            temp -> next = nullptr;
            res.push_back(head);
            head = nextHead;
            partsAmount--;
        }
        return head;
    }
};



int main(){
    Solution solution;
    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(4);
    ListNode* five = new ListNode(5);
    ListNode* six = new ListNode(6);
    ListNode* seven = new ListNode(7);
    ListNode* eight = new ListNode(8);
    ListNode* nine = new ListNode(9);
    ListNode* ten = new ListNode(10);

    one->next = two;
    two->next = three;
/*     three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = eight;
    eight->next = nine;
    nine->next = ten; */

    vector<ListNode*> res = solution.splitListToParts(one,5);
    for (auto i : res){
        print(i);
    }

    deleteList(one);
}