#include "Debug.cpp"

class Solution {
public:
    int heightLeft (TreeNode* root){
        if (!root) return 0;
        return heightLeft(root->left) + 1;
    }

    int heightRight(TreeNode* root){
        if (!root) return 0;
        return heightRight(root->right) + 1;
    }
    int countNodes(TreeNode* root) {
        int hl =  heightLeft(root);
        int hr = heightRight(root);

        if (hl == hr) return (pow(2,hl)-1);
        return countNodes(root->left) + countNodes(root->right)+1;
    }
    /*Ý tưởng cơ bản: muốn tính số node trong complete binary tree, thì phải phải tính số node trong
    full binary tree, và số node bị thừa ra. Nếu chiều cao subtree trái = chiều cao subtree phải thì đó là full binary tree
    ngược lại thì phải tìm được số node trong full binary subtree trái/phải và số node bị thừa ra */
};