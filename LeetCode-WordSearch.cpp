#include <iostream>
#include <vector>
#include <string> 
using namespace std;
void print(vector<vector<int>>& arg){
    for (int i = 0; i < arg.size(); i++){
        for (int j = 0; j < arg[0].size(); j++){
            cout << arg[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isInRange(int currIndex,int maxRange){
    return 0 <= currIndex && currIndex < maxRange;
}

class Solution {
public:
    vector<vector<int>> visitTable;
    bool res;
    bool Search(int m, int n, vector<vector<char>>& board, int i, string word){ //iChar is index of Char that we are searching for
        if (!isInRange(m,board.size()) || !isInRange(n,board[0].size()))
            return false;

        if (visitTable[m][n] == 1)
            return false;

        if (board[m][n] != word[i])
            return false;

        if (board[m][n] == word[i] && i == word.size()-1)
            return true;


        visitTable[m][n] = 1;
        // print(visitTable);
        res = Search(m,n-1,board,i+1,word) || //left
              Search(m,n+1,board,i+1,word) || //right
              Search(m-1,n,board,i+1,word) || //up
              Search(m+1,n,board,i+1,word);   //down
        visitTable[m][n] = 0;
        return res;    
    }


    bool exist(vector<vector<char>>& board, string word) {
        vector<int> temp (board[0].size(),0);
        visitTable = vector<vector<int>> (board.size(),temp);

        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (Search(i,j,board,0,word))
                    return true;
            }
        }
        return false;
    }
};


int main(){
    vector<vector<char>> inp = {{'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}};
    Solution solution;
    cout << solution.exist(inp,"SEE");
}