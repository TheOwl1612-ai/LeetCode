#include "Debug.cpp"
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root,LONG_MIN,LONG_MAX);


    }
    bool validate(TreeNode* root, long min, long max) {
        if (!root) return true;
        if (root-> val <= min || root -> val >= max) return false;
        return validate(root->left, min,root->val) && validate(root->right,root->val,max);
    }
};

int main(){
    Solution solution;
    TreeNode* four = new TreeNode(4);
    TreeNode* two = new TreeNode(2);
    TreeNode* six = new TreeNode(6);
    TreeNode* one = new TreeNode(1);
    TreeNode* nine = new TreeNode(9);
    TreeNode* five = new TreeNode(5);
    TreeNode* seven = new TreeNode(7);
    TreeNode* zero = new TreeNode(0);
    TreeNode* eight = new TreeNode(8);

    four->left = two;
    four->right = six;

    two->left = one;
    two->right = nine;

    six->left = five;
    six->right = seven;

    one->left = zero;
    seven -> right = eight;

    solution.isValidBST(four);
    deleteTree(four);

}