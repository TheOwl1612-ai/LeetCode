#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

void print(const vector<vector<int>>& arg){
    for (const vector<int>& row : arg){
        for (const int val : row){
            cout << val << " ";
        }
        cout << endl;
    }
}

void print(const vector<int>& arg){
    for (const int val : arg){
        cout << val << " "; 
    }
    cout << endl;
}
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> res(2,0);
        size_t nums = grid.size()*grid.size();
        vector<int> keys (nums+1,0);

        for (const vector<int>& row : grid){
            for (const int val : row){
                keys[val]++;
            }
        }

        for (int i = 1; i < keys.size(); i++){
            if (keys[i] == 0){
                res[1] = i;
            }
            if (keys[i] == 2){
                res[0] = i;
            }
        }
        return res;
    }
};




int main(){
    Solution solution;
    vector<vector<int>> inp = {{1,3},{2,2}};
    solution.findMissingAndRepeatedValues(inp);

}