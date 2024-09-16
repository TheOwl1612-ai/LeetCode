#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int data): val(data), left(nullptr), right(nullptr){}
    TreeNode(int data, TreeNode* left, TreeNode* right): val(data), left(left), right(right){}
    ~TreeNode(){
        delete left;
        delete right;
    }
};
bool SameTree(TreeNode* root, TreeNode* subRoot){
    if (root == nullptr && subRoot == nullptr)
        return true;
    if (root == nullptr || subRoot == nullptr)
        return false;

    if (root -> val != subRoot -> val)
        return false;
    return SameTree(root -> left, subRoot -> left) && SameTree(root -> right, subRoot -> right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot){
    if (SameTree(root, subRoot))
        return true;
    if (root == nullptr)
        return false;
    return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);  
}

int main(){
    TreeNode *a, *b, *c, *d, *e, *f, *a_sub, *b_sub, *c_sub;
    a = new TreeNode(3);
    b = new TreeNode(4);
    c = new TreeNode(5);
    d = new TreeNode(1);
    e = new TreeNode(2);

    a_sub = new TreeNode(4);
    b_sub = new TreeNode(1);
    c_sub = new TreeNode(2);

    a -> left = b;
    a -> right = c;

    b -> left = d;
    b -> right = e;

    a_sub -> left = b_sub;
    a_sub -> right = c_sub;

    cout << isSubtree(a,a_sub) << endl;
    
    delete a;
    delete a_sub;

}