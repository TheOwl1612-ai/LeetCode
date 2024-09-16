#include "Debug.cpp"
class Solution {
public:
    int maxArea(vector<int>& height) {
        int v = 0;    
        int l = 0;
        int r = height.size()-1;
        while (l < r){
            v = max(v,(r-l)*min(height[l],height[r]));
            if (height[l] < height[r]) l++;
            else if (height[l] > height[r]) r--;
            else{
                r--;
                l++;
            }
        }
        return v;
    }
};

int main(){
    Solution solution;
    vector<int> inp {1, 3, 2, 5, 2, 3, 1};
    cout << solution.maxArea(inp) << endl;
}