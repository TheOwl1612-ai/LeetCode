#include "Debug.cpp"
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trusts) {
        vector<int> trustAmount (n+1,0);
        for (auto trust : trusts){
            trustAmount[trust[0]]--;
            trustAmount[trust[1]]++;
        }
        for (int i = 1; i < n+1; i++){
            if (trustAmount[i] == n-1){
                return i;
            }
        }
        return -1;

    }
};

int main(){
    Solution solution;
    vector<vector<int>> vec = {
    {1, 2}, 
    {1, 3}, 
    {2, 1}, 
    {2, 3}, 
    {1, 4}, 
    {4, 3}, 
    {4, 1}
};
    cout << solution.findJudge(4,vec);
}