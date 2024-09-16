#include "Debug.cpp"

class Solution {
public:
    vector<vector<int>> res {};
    void backtrack(vector<int>& candidates, vector<int>& curr, int currSum, int first, int target){
        if (currSum == target){
            res.push_back(curr);
            return;
        }
        
        // if (currSum > target) return;

        for (first; first < candidates.size(); first++){
            if (currSum + candidates[first] > target) return; 
            curr.push_back(candidates[first]);
            backtrack(candidates,curr,currSum+candidates[first],first+1,target);
            curr.pop_back();
            while (first + 1 < candidates.size() && candidates[first] == candidates[first+1]){
                first++;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());    
        vector<int> temp {};
        backtrack(candidates, temp, 0, 0, target);
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp {10,1,2,7,6,1,5};
    int target = 8;
    solution.combinationSum2(temp,target);
}