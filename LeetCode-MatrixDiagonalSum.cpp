#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        int i = 0;
        int j = mat.size()-1;
        int sum = 0;
        while (i < mat.size() && j >= 0){
            cout << mat[i][i] << " " << mat[j][j] << endl;
            sum += mat[i][i] + mat[i][j];

            i++;
            j--;
        }
        if (mat.size()%2 != 0){
            return sum - mat[mat.size()/2][mat.size()/2];
        }
        return sum;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> test {{1,2,1,1},
                            {1,10,1,1},
                            {1,1,5,9},
                            {6,1,1,1}};
    cout << solution.diagonalSum(test);

    return 0;

}