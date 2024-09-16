#include "Debug.cpp"

class Solution {
public:
    void markVisited(vector<vector<char>>& grid, int i, int j){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] == '0') return;

        grid[i][j] = '0';
        markVisited(grid,i,j-1);
        markVisited(grid,i,j+1);
        markVisited(grid,i-1,j);
        markVisited(grid,i+1,j);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    markVisited(grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }
};

int main(){
std::vector<std::vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution solution;
    int res =solution.numIslands(grid);
    cout << res;

}