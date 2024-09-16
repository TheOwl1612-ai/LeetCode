#include <iostream>
#include <algorithm>
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

class Solution{
    public:
    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxDiameter;
    }

    private:
    int maxDepth(TreeNode* root){
        if (root == nullptr){
            return 0;
        }

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        maxDiameter = std::max(maxDiameter, leftDepth + rightDepth + 1);

        return std::max(leftDepth,rightDepth) + 1;
    }

};
int main(){
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    Solution solution;
    std::cout << solution.diameterOfBinaryTree(a);
    delete a;

}