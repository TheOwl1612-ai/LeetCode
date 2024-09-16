#include "Debug.cpp"
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); ++i){
            if (map.count(nums[i]) && i - map[nums[i]] <= k) return true;
            map[nums[i]] = i;
        }
        return false;
    }
};
int main(){
    Solution solution;
    vector<int> inp {1,2,3,1};
    bool res = solution.containsNearbyDuplicate(inp,3);
    cout << res;
}