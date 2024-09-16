#include <iostream>
#include <unordered_map>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(): val(0), left(nullptr), right(nullptr){}
    Node(int val): val(val), left(nullptr), right(nullptr){}
    Node(int val, Node* left, Node* right): val(val), left(left), right(right){}
    ~Node(){
        delete left;
        delete right;
    }
};
bool SymmetricTree(Node* p, Node* q){
    if (p == nullptr && q == nullptr){
        return true;
    }
    else if( p == nullptr || q == nullptr){
        return false;
    }

    if (p -> val == q -> val){
        return SymmetricTree(p -> left,q->right) && SymmetricTree(p -> right, q -> left);
    }
    return false;
}
int main(){
    Node* root = new Node(1);
    Node* a2 = new Node(2);
    Node* b2 = new Node(2);
    Node* a3 = new Node(3);
    Node* b3 = new Node(3);

    root -> left = a2;
    root -> right = b2;

    a2 -> right = a3;
    
    b2 -> right = b3;

    if (root -> left == nullptr && root -> right == nullptr){
        cout << true;
    }
    else{
        cout << SymmetricTree(root -> left, root -> right);
    }

    delete root;
}