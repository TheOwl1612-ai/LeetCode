#include <iostream>
#include <vector>
#include <climits>
using namespace std;


void print(const vector<int>& arg){
    for (const int i : arg){
        cout << i << " ";
    }
    cout << endl;
}
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        size_t m = matrix.size(); //row
        size_t n = matrix[0].size(); //col

        vector<int> minRow (m,INT_MAX);
        vector<int> maxCol (n,INT_MIN);

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                minRow[i] = min(matrix[i][j],minRow[i]);
                maxCol[j] = max(matrix[i][j], maxCol[j]);
            }
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (minRow[i] == maxCol[j]){
                    res.push_back(matrix[i][j]);
                }
            }
        }
        return res;
    }
};

int main(){
    vector<vector<int>> inp = {{3,7,12},{9,8,10},{15,6,11}};
    Solution solution;
    print(solution.luckyNumbers(inp));
}
