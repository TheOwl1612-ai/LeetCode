#include <vector>
#include <iostream>
using namespace std;
void print(vector<int>& foo){
    for (int bar : foo)
        cout  << bar << " ";
    cout << endl;
}
void print(vector<vector<int>> arg){
    for (vector<int> foo : arg)
        print(foo);
    cout << endl;
}


class Solution {
public:
    vector<vector<int>> getRow(int numRows) {
        if (numRows == 1)
            return {{1}};

        if (numRows == 2){
            return {{1},{1,1}};
        }

        vector<vector<int>> prevRows = getRow(numRows-1);
        vector<int> prevRow = prevRows.at(numRows-2);
        vector<int> newRow (numRows,0);
        newRow[0] = newRow[numRows-1] = 1;

        for (int i = 0; i <= (numRows-2)/2; i++){
            newRow[i+1] = newRow[numRows-i-2] = (prevRow.at(i) + prevRow.at(i+1));
        }
        prevRows.push_back(newRow);
        return prevRows;
    }
};

int main(){
    Solution solution;
    solution.getRow(10);
}
