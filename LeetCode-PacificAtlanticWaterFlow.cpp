#include "Debug.cpp"

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific (heights.size(), vector<bool> (heights[0].size(),false));
        vector<vector<bool>> atlantic (heights.size(), vector<bool> (heights[0].size(),false));

        int r = heights.size();
        int c = heights[0].size();
        for (int i = 0; i < r; i++) dfs(heights,pacific,INT_MIN,i,0);
        for (int i = 0; i < c; i++) dfs(heights,pacific,INT_MIN,0,i);

        for (int i = 0; i < r; i++) dfs(heights,atlantic,INT_MIN,i,c-1);
        for (int i = 0; i < heights[0].size(); i++) dfs(heights,atlantic,INT_MIN,r-1,i);

        vector<vector<int>> res {};
        for (int i = 0; i < heights.size(); i++){
            for (int j = 0; j < heights[0].size(); j++){
                if (pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& grid, int prev, int r, int c){
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || matrix[r][c] < prev || grid[r][c]){
            return;
        }

        grid[r][c] = true;
        vector<vector<int>> dirs {{0,1},{1,0},{0,-1},{-1,0}};
        for (auto dir : dirs){
            dfs(matrix,grid,matrix[r][c],r + dir[0], c + dir[1]);
        }
    }
};

int main(){
    Solution solution;
    vector<vector<int>> heights = {
    {1, 2, 2, 3, 5},
    {3, 2, 3, 4, 4},
    {2, 4, 5, 3, 1},
    {6, 7, 1, 4, 5},
    {5, 1, 1, 2, 4}};
    solution.pacificAtlantic(heights);
};
    