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
    vector<int> getRow(int n) {
        vector<int> newRow (n+1,1);
        long prev = 1;
        for (int r = 1; r < n; r++){
            prev = prev*(n-r+1)/r;
            newRow.at(r) = prev;
        }
        return newRow;  
    }
};

int main(){
    Solution solution;
    solution.getRow(4);
}
