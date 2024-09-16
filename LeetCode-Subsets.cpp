#include <vector>
#include <iostream>
using namespace std;


void print(vector<vector<int>> foo){
    for (vector<int> bar : foo){
        for (int i : bar){
            cout << i << " ";
        }
        cout << endl;
    }
}
class Solution {
public:
    vector<vector<int>> res;
    int n,k;

    void backtrack(int first, vector<int>& curr, vector<int>& nums){
        if (curr.size() == k) res.push_back(curr);

        for (int i = first; i < n; i++){
            curr.push_back(nums[i]);
            backtrack(i+1,curr,nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        for (k = 0; k <= n; k++){
            vector<int> temp;
            backtrack(0,temp,nums);
        }
        return res;
    }
};
int main(){
    Solution solution;
    vector<int> inp = {1,2,3};
    solution.subsets({inp});
}