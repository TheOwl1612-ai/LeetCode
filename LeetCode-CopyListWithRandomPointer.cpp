#include "Debug.cpp"
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    unordered_map<Node*, Node*> map;
    Node* copyRandomList(Node* head){
        if (!head) return nullptr;

        Node* newHead = Node(head->val);
        newHead->random = head->random;
        map.insert({head,newHead});
        newHead->next = copyList(head->next);
        newHead->random = map[newHead->random];
        return newHead;
    }
};

int main(){

}