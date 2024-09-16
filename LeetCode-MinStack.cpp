#include "Debug.cpp"


struct Node{
    int val;
    int min;
    Node* next;

    Node(int val,int min): val(val), min(min), next(nullptr){};

};
class MinStack {
public:
    Node* head = nullptr;
    
    void push(int currVal) {
        if (head == nullptr)
            head = new Node(currVal,currVal);
        else{
            Node* newNode = new Node(currVal,min(head->min,currVal));
            newNode -> next = head;
            head = newNode;
        }
    }
    void pop() {
        head = head -> next;
    }
    
    int top() {
        return head -> val;
    }
    
    int getMin() {
        return head->min;
    }
};
