#include <iostream>
#include <unordered_map>
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
void print(unordered_map<Node*,int> target){
    for (auto pair : target){
        cout << pair.first -> data << endl;
    }
}
bool isSameTree(Node* p, Node* q) {
        if (p == nullptr && q == nullptr){
            return true;
        }
        
        if (p == nullptr || q == nullptr){
            return false;
        }

        if (p -> data == q -> data){
            return isSameTree(p -> left,q -> left) && isSameTree(p -> right, q -> right);
        }
        return false;
    }


int main(){
    Node* Node1 = new Node(1);
    Node* Node1b = new Node(1);



    Node1 -> left = new Node(2);
    Node1 -> right = new Node(1);

    Node1b -> left = new Node(1);
    Node1b -> right = new Node(2);
    cout << isSameTree(Node1, Node1b);

    delete Node1;
    delete Node1b;
}