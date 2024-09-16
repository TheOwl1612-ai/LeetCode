
#include "Debug.cpp"
using namespace std;


void print(vector<vector<int>>& arg){
    for (auto foo : arg){
        for (auto bar : foo)
            cout << bar << " ";
        cout << endl;
    }
    cout << endl;
}

void print(vector<int>& arg){
    for (auto foo : arg){
        cout << foo << " ";
    }
    cout << endl << endl;
}

class Solution {
public:
    vector<vector<int>> res {};
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            int j = i+1;
            int k = nums.size()-1;
            int target = -nums[i];

            while (j < k){
                if (nums[j] + nums[k] < target) j++;
                else if (nums[j] + nums[k] > target) k--;
                else {
                    vector<int> triplet = {nums[i],nums[j],nums[k]};
                    res.push_back(triplet);
                    while (j < k && nums[j] == triplet[1]) j++;
                    while (j < k && nums[k] == triplet[2]) k--;
                }
            }

            while (i + 1 < nums.size() && nums[i+1] == nums[i]){
                i++;
            }
        }
        return res;
    }
};

int main(){
    vector<int> inp {-1,0,1,2,-1,-4};
    Solution solution;
    solution.threeSum(inp);
}