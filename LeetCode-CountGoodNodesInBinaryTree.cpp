#include "Debug.cpp"
class Solution {
public:
    int helper (TreeNode* root, int currMax) {
        if (!root) return 0;
        int ifMax = root->val >= currMax;
        return helper(root->left,max(currMax,root->val)) + helper(root->right,max(currMax,root->val)) + ifMax;
    }
    int goodNodes(TreeNode* root) {
        return helper(root,root->val);
    }
};


int main(){
    Solution solution;
    TreeNode* a = new TreeNode(3);
    TreeNode* b = new TreeNode(1);
    TreeNode* c = new TreeNode(4);
    TreeNode* d = new TreeNode(3);
    TreeNode* e = new TreeNode(1);
    TreeNode* f = new TreeNode(5);

    a->left = b;
    a->right = c;
    b->left = d;
    c->left = e;
    c->right = f;

    int res = solution.goodNodes(a);
    deleteTree(a);
}