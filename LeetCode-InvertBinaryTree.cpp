#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

    ~TreeNode(){
        delete this->left;
        delete this->right;   
    }
};

void print(TreeNode* root){
    if (root == nullptr)
        return;
    print(root->left);
    std::cout << root->val << std::endl;
    print(root->right);
}
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr){
        return root;
    }
    std::swap(root->left,root->right);
    
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

int main(){
    TreeNode* a = new TreeNode(4);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(7);
    TreeNode* d = new TreeNode(1);
    TreeNode* e = new TreeNode(3);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(9);

    a->left = b;
    a->right = c;
    
    b->left = d;
    b->right = e;

    c->left = f;
    // c->right = g;

    invertTree(a);
    print(a);
    delete a;

}