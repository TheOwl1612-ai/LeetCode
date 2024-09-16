#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 1; i < row-1; i++){
            vector<int> temp;
            for (int j = 1; j < col-1; j++){   
                temp.push_back(max3x3(i,j,grid));
            }
            res.push_back(temp);
        }
        
        print(res);
        return res;
    }


private:
    void print(vector<vector<int>>& grid){
        for (vector<int> i : grid){
            for (int j : i){
                cout << j << " ";
            }
            cout << "\n";
        }
    }

    int max3x3(int currRow,int currCol, vector<vector<int>>& grid){
        int globalMax = 0;
        for (int i = currRow-1; i < currRow+2; i++){
            for (int j = currCol-1; j < currCol + 2; j++){
                globalMax = max(globalMax, grid[i][j]);
            }
        }
        return globalMax;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> inp = {{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
    vector<vector<int>>res = solution.largestLocal(inp);
}