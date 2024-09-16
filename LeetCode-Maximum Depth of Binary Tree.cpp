#include <iostream>
#include <cmath>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(): data(0), left(nullptr), right(nullptr){}
    Node(int data): data(data), left(nullptr), right(nullptr){}
    ~Node(){
        delete left;
        delete right;
    }
};

int MaxDepth(Node* curr){
    if (curr == nullptr)
        return 0;
    return max(1 + MaxDepth(curr -> left),1+ MaxDepth(curr -> right));

}
int main(){
    Node* Node2 = new Node(2);
    Node* Node3 = new Node(3);
    Node* Node4 = new Node(4);
    Node* Node5 = new Node(5);
    Node* Node7 = new Node(7);

    Node5 -> left = Node3;
    Node5 -> right = Node7;
    Node3 -> left = Node2;
    Node3 -> right = Node4;
    
    cout << MaxDepth(Node5);

    delete Node5;
}

