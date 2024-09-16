#include <iostream>
#include <cmath>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(): data(0), left(nullptr), right(nullptr){}
    Node(int data): data(data), left(nullptr), right(nullptr){}
    Node(int data, Node* left, Node* right): data(data), left(left), right(right){}
    ~Node(){
        delete left;
        delete right;
    }
};


int Balanced(Node* root){
    if (root == nullptr){
        return 0;
    }
    int depth_left = Balanced(root -> left);
    int depth_right = Balanced(root -> right);
    if (abs(depth_left - depth_right) > 1 || depth_left == -1 || depth_right == -1){
        return -1;
    }
    return 1 + max(depth_left,depth_right);
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(4);
    Node* d = new Node(8);
    Node* e = new Node(5);
    Node* f = new Node(3);
    Node* g = new Node(6);

    a -> left = b;
    a -> right = f;

    b -> left = c;
    b -> right = e;

    c -> left = d;
    c -> left = d;

    f -> left = g;
    
    if (Balanced(a) != -1){
        cout << true << endl;
    }
    else{
        cout << false << endl;
    }
    delete a;

}