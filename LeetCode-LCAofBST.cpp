#include "Debug.cpp"


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root -> val > p -> val && root -> val > q -> val) return lowestCommonAncestor(root->left,p,q);
        if (root -> val < p -> val && root -> val < q -> val) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};

int main (){
    Solution solution;
    TreeNode* six = new TreeNode(6);
    TreeNode* two = new TreeNode(2);
    TreeNode* eight = new TreeNode(8);
    TreeNode* zero = new TreeNode(0);
    TreeNode* four = new TreeNode(4);
    TreeNode* three = new TreeNode(3);
    TreeNode* five = new TreeNode(5);
    TreeNode* seven = new TreeNode(7);
    TreeNode* nine = new TreeNode(9);

    six->left = two;
    six->right = eight;

    two->left = zero;
    two->right = four;

    four->left = three;
    four->right = five;

    eight->left = seven;
    eight->right = nine;

    cout << solution.lowestCommonAncestor(six,five,nine) -> val;

}

