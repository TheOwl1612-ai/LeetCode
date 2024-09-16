#include <vector>
#include <iostream>
using namespace std;

void print(const vector<int>& arg){
    for (auto foo : arg){
        cout << foo << " ";
    }
    cout << endl;
}
void print(const vector<vector<int>>& arg){
    for (auto foo : arg){
        for (auto bar : foo){
            cout << bar << " " ;
        }
        cout << endl;
    }
    cout << endl;
}
class Solution {
public:
    size_t n;
    vector<vector<int>> res;

    void backtrack(int first, int currSum, vector<int>& currCombi, int target, vector<int>& candidates){
        if (currSum == target){
            res.push_back(currCombi);
            return;
        }

        if (currSum > target)
            return;

        for (int i = first; i < n; i++){
            currCombi.push_back(candidates[i]);
            backtrack(i, currSum + candidates[i],currCombi, target, candidates);
            currCombi.pop_back();
        }   

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> currCombi {};
        backtrack(0,0,currCombi,target,candidates);
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> inp = {3,5,2,6,1};
    solution.combinationSum(inp,6);
}