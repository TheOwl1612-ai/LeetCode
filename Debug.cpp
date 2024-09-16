#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){};
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};

};

void deleteTree (TreeNode* root){
    if (!root) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
void deleteList(ListNode* head){
    while (head){
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}
void print(ListNode* head){
    while (head){
        cout << head -> val << " ";
        head = head->next;
    }
    cout << endl;
}
void print(const vector<char>& vect){
    for (char i : vect)
        cout << i << " ";
    cout << endl;
}
void print(const vector<int>& vect){
    for (int i : vect)
        cout << i << " ";
    cout << endl;
}

void print(const vector<vector<int>>& matrix){
    for (vector<int> vect : matrix)
        print(vect);
    cout << endl;
}
void print(const vector<vector<char>>& matrix){
    for (vector<char> vect : matrix)
        print(vect);
    cout << endl;
}



