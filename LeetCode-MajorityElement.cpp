#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int res;

        for (int i : nums){
            if (count == 0) 
                res = i;
            if (i == res)
                count++;
            else
                count--;
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> inp {2,2,1,1,2,2};
    cout << solution.majorityElement(inp) << endl;
}