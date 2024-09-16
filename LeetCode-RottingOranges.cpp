#include "Debug.cpp"

class Solution {
public:
    queue<vector<int>> q;
    int t = 0;
    int count = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        /* print(grid); */
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 2) q.push({i,j});
                else if (grid[i][j] == 1) count++;
            }
        }


        while (!q.empty() && count > 0){
            t++;
            size_t size = q.size();
            for (int _ = 0; _ < size; _++){
                const int& i = q.front()[0];
                const int& j = q.front()[1];
                mark(grid,i,j-1);
                mark(grid,i,j+1);
                mark(grid,i-1,j);
                mark(grid,i+1,j);
                q.pop();
            /* print(grid); */
            }
        }

        if (count == 0) return t;
        return -1;
    }
private:
    bool outOfRange(int i, int range){
        if (i >= range || i < 0) return true;
        return false;
    }


    void mark(vector<vector<int>>& grid, int i, int j){
        if (!outOfRange(i,grid.size()) && !outOfRange(j,grid[0].size()) && grid[i][j] != 2 && grid[i][j] != 0){
            grid[i][j] = 2;
            q.push({i,j});
            count--;
        }

    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> matrix = {
        {2, 1, 1},
        {1, 1, 1},
        {0, 1, 2}
    };
    int res = solution.orangesRotting(matrix);
    cout << res;
}