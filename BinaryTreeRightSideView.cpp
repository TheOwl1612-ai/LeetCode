#include "Debug.cpp"

class Solution {
public:
    int maxDepth = 1;
    vector<int> res {};
    void helper(TreeNode* root, int currDepth) {
        if (!root) return;

        if (currDepth > maxDepth) {
            maxDepth = currDepth; 
            res.push_back(root->val);
        }
        helper(root->right, currDepth+1);
        helper(root->left, currDepth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
       helper(root,1);
       return res;
    }
};

int main(){
    Solution solution;
    TreeNode* one = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* five = new TreeNode(5);
    TreeNode* six = new TreeNode(6);

    one->left = two;
    one->right = three;
    two->right = five;
    three->right = four;
    five->right = six;

    print(solution.rightSideView(one));
    deleteTree(one);
}