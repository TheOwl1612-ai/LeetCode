#include "Debug.cpp"

class Solution {
public:
    int rob(vector<int>& nums, int n, int end) {
        int res = 0;
        vector<int> dp (n+2,0);
        for (int i = n - 1; i >= end; i--){
            dp[i] = max(dp[i+1],nums[i] + dp[i+2]);
        }
        return dp[end];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(rob(nums,nums.size(),1),rob(nums,nums.size()-1,0));
    }
};

int main(){
    Solution solution;
    vector<int> money {1};
    cout << solution.rob(money);
}