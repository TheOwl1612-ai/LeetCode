#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode(){
        delete left;
        delete right;
    }
};

bool hasPathSum(TreeNode* root, int targetSum){
    if (root == nullptr)
        return false;
    
    int complement = targetSum - (root -> val);
    if (root -> left == nullptr && root -> right == nullptr && complement == 0){
        return true;
    }

    return hasPathSum(root -> left, complement) || hasPathSum(root -> right, complement);
}

int main(){
    TreeNode* a = new TreeNode(5);
    TreeNode* b = new TreeNode(4);
    TreeNode* c = new TreeNode(8);
    TreeNode* d = new TreeNode(11);
    TreeNode* e = new TreeNode(7);
    TreeNode* f = new TreeNode(2);
    TreeNode* g = new TreeNode(13);
    TreeNode* h = new TreeNode(4);
    TreeNode* i = new TreeNode(1);


    a -> left = b;
    a -> right = c;

    b -> left = d;

    d -> left = e;
    d -> right = f;

    c -> left = g;
    c -> right = h;

    h -> right = i;

    cout << hasPathSum(a, 22);
    delete a;

}