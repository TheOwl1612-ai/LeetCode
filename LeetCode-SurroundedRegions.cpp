#include "Debug.cpp"

class Solution {
public:
    vector<vector<bool>> visited;
    void notSurrounded(vector<vector<char>>& board, int x, int y){
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == 'X' || visited[x][y] ){
            return;
        } 

        visited[x][y] = true;
        vector<vector<int>> dirs {{0,1},{1,0},{0,-1},{-1,0}};

        for (auto dir: dirs){
            notSurrounded(board,x + dir[0], y + dir[1]);
        }
    }

    void capture(vector<vector<char>>& board, int x, int y){
            if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visited[x][y]){
                return;
            } 

            visited[x][y] = true;
            board[x][y] = 'X';
            vector<vector<int>> dirs {{0,1},{1,0},{0,-1},{-1,0}};

            for (auto dir: dirs){
                capture(board,x + dir[0], y + dir[1]);
            }
        }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        visited = vector<vector<bool>> (rows, vector<bool> (cols, false));

        //traverse outer rows & cols
        
        //first row
        for (int i = 0; i < cols; i++){
            if (board[0][i] == 'O') {
                notSurrounded(board,0,i);
            }
        }

        //last row
        for (int i = 0; i < cols; i++){
            if (board[rows-1][i] == 'O') {
                notSurrounded(board,rows-1,i);
            }
        }

        //first column
        for (int i = 0; i < rows; i++){
            if (board[i][0] == 'O') {
                notSurrounded(board,i,0);
            }
        }

        //last column
        for (int i = 0; i < rows; i++){
            if (board[i][cols-1] == 'O') {
                notSurrounded(board,i,cols-1);
            }
        }

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (board[i][j] == 'O' && visited[i][j] == false) capture(board,i,j);
            }
        }
    }
};

int main() {
    std::vector<std::vector<char>> matrix = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    Solution solution;
    solution.solve(matrix);
    print(matrix);
    return 0;
}