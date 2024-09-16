#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int res = 0;

        while (!grid.empty()){
            int maxToBeAdded = 0;

            for (vector<int>& row : grid){
                if (row.empty()){
                    grid.erase(grid.begin());
                    continue;           
                }
                
                int indexOfMax = FindMax(row);
                maxToBeAdded = max(maxToBeAdded,row[indexOfMax]);
                row.erase(row.begin() + indexOfMax);
            }
            print(grid);
            res+= maxToBeAdded;
        }
        return res;
    }


private:
    int FindMax(const vector<int>& arg){
        int globalMax = 0;
        int indexOfMax = 0;
        for (int i = 0; i < arg.size(); i++){
            if (arg[i] > globalMax){
                globalMax = arg[i];
                indexOfMax = i;
            }
        }   
        return indexOfMax;
    }

    void print(const vector<vector<int>>& arg){
        for (auto i : arg){
            for (auto j : i){
                cout << j << " ";
            }
            cout << endl;
        }

    }
};


int main(){
    Solution solution;

    // vector<vector<int>> inp = {{1,2,4},{3,3,1}};
    vector<vector<int>> inp = {{3,3,3},{1,2,3}};
    cout << solution.deleteGreatestValue(inp);
}