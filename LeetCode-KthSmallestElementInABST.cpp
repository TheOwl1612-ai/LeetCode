#include "Debug.cpp"
class Solution {
public:
    int k;
    int res;
    int count = 0;
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return;

        kthSmallest(root->left,k);
        count += 1;
        if (count == k) res = root->val;
        kthSmallest(root->right,k);
        return res;
    }
};

int main(){
    Solution solution;
}