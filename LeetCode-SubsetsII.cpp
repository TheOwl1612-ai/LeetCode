#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<vector<int>> arg){
    for (auto foo : arg){
        for (auto bar : foo){
            cout << bar << " ";
        }
        cout << endl;
    }
    cout << endl;
}


class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int first, vector<int>& curr, vector<int>& nums){
        if (first >= nums.size()){
            res.push_back(curr);
            return;
        }

        //take i
        curr.push_back(nums.at(first));
        backtrack(first+1,curr,nums);
        curr.pop_back();

        while (first + 1 < nums.size() && nums.at(first) == nums.at(first+1)){
            first++;
        }
        backtrack(first+1,curr,nums);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp {};
        sort(nums.begin(),nums.end());
        backtrack(0,temp,nums);
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> inp {4,4,4,1,4};
    solution.subsetsWithDup(inp);
}