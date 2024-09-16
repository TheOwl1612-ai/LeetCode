#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> hash (nums.begin(),nums.end());
        int maxLength = 0;
        for (auto &i : nums){
            if (!hash.count(i-1)){
                int length = 1;
                while (hash.count(i+length))
                    ++length;
                maxLength = max(maxLength,length);
            }
        }
        return maxLength;
    }
};

int main(){
    Solution solution;
    vector<int> inp {9,1,4,7,3,-1,0,5,8,-1,6};
    cout << solution.longestConsecutive(inp);
}