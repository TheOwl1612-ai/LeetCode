#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (const vector<int>& currRow : grid){
            int currColIndex = currRow.size()-1;
            while (currColIndex >= 0 && currRow[currColIndex] < 0){
                currColIndex--;
            }
            count+=currRow.size()-currColIndex-1;
        }

        return count;
    }
};

int main(){
    vector<vector<int>> inp {{4,3,2,0},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    Solution solution;
    cout << solution.countNegatives(inp) << endl;
}