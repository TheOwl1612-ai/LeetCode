#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& arg){
    for (int i : arg){
        cout << i << " ";
    }
    cout << endl;
}

void print(vector<vector<int>> arg){
    for (auto i : arg){
        for (auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}
class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int begin, vector<int>& nums){
        if (begin >= nums.size()){
            res.push_back(nums);
            return;
        }

        for (int i = begin; i < nums.size(); i++){
            swap(nums[begin],nums[i]);
            backtrack(begin+1, nums);
            swap(nums[begin],nums[i]);
        }
        
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0,nums);
        return res;
    }
};


int main(){
    Solution solution;
    vector<int> inp = {1,2,3};
    solution.permute(inp);
    
}