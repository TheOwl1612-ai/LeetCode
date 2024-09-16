#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (vector<int>& row : image){
            int i = 0;
            int j = row.size()-1;
            while ( i <= j ){
                row[i] = invert(row[i]);
                if (i != j)
                    row[j] = invert(row[j]);
                swap(row[i],row[j]);
                i++;
                j--;
            };
        }
        print(image);
        return image;
    }
private:
    int invert(int arg){
        if (arg == 0)
            return 1;
        return 0;
    }

    void print(vector<vector<int>> arg){
        for (auto i : arg){
            for (auto j : i){
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    void print(vector<int> arg){
        for (auto i : arg){
            cout << i << " ";
        }
        cout << "\n";

    }
};

int main(){
    Solution solution;

    vector<vector<int>> inp{{1,1,0,0},
                            {1,0,0,1},
                            {0,1,1,1},
                            {1,0,1,0}};
    auto res = solution.flipAndInvertImage(inp);
}