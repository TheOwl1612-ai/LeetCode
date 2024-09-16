#include <iostream>
#include <cmath>
#include <vector>
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

TreeNode* BuildTree(int l, int r, vector<int> nums){
    int m = (l+r)/2;
    TreeNode* root = new TreeNode(nums[m]);
    root -> left = BuildTree(l,m-1,nums);
    root -> right = BuildTree(m+1,r,nums);
    return root;
}


int Solution (TreeNode* root){
    if (root == nullptr){
        return -1;
    }
    if (root -> left == nullptr && root -> right == nullptr)
        return 1;

    int left_depth = Solution(root -> left);
    int right_depth = Solution(root -> right);
    
    if (left_depth == -1 ){
        return 1+right_depth;
    }
    if (right_depth == -1){
        return 1+left_depth;
    }

    return min(1+left_depth, 1+right_depth);
    

}

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* a = new TreeNode(2);
    TreeNode* b = new TreeNode(3);
    TreeNode* c = new TreeNode(4);

    TreeNode* d = new TreeNode(2);
    TreeNode* e = new TreeNode(3);

    root -> left = a;
    a -> left = b;
    b -> left = c;

    root -> right = d;
    d -> right = e;
    cout << Solution(root);

    delete root;
}