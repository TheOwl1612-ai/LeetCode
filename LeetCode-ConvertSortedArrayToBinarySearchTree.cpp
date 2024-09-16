#include <iostream>
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

void print(TreeNode* root){
    if (root == nullptr)
        return;

    print(root -> left);
    cout << root -> val << " ";
    print(root -> right);
}

TreeNode* helper(int l, int r, vector<int>& nums){
    if (l > r){
        return nullptr;
    }
    int m = (l+r)/2;
    cout << m << endl;
    TreeNode* root = new TreeNode(nums[m]);
    root -> left = helper(l,m-1,nums);
    root -> right = helper(m+1,r,nums);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(0,nums.size()-1,nums);
}


int main(){
    vector<int> arr = {1,7,9,15,20};
    TreeNode* res = sortedArrayToBST(arr);

}