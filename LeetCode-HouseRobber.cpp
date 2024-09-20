#include "Debug.cpp"

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> dp (n+2,0);
        for (int i = n - 1; i >= 0; i--){
            dp[i] = max(dp[i+1],nums[i] + dp[i+2]);
        }
        return dp[0];
    }
};

int main(){
    Solution solution;
    vector<int> money {2,7,9,3,1};
    cout << solution.rob(money);
}