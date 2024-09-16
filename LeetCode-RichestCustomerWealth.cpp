#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int globalMax = 0;
        for (vector<int> i : accounts){
            int currSum = 0;
            for (int j : i){
                currSum += j;
            }
            globalMax = max(globalMax,currSum);
        }
        
        return globalMax;
    }

};

int main(){
    Solution solution;

    vector<vector<int>> input = {{2,8,7},{7,1,3},{1,9,5}};
    cout << solution.maximumWealth(input) << endl;

}