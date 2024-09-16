#include "Debug.cpp"

class Solution {
public:
    int binarySearch(vector<vector<int>>& matrix, int target){
        int low = 0;
        int high = matrix.size()-1;
        int firstcol = 0;
        int lastcol = matrix[0].size()-1;
        while (low < high){
            int mid = low + (high-low)/2;
            if (matrix[mid][firstcol] <= target && target <= matrix[mid][lastcol]) return mid;
            else if(matrix[mid][firstcol] > target) high = mid-1;
            else if(matrix[mid][lastcol] < target) low = mid + 1;
        }   
        return low;
    }
    int binarySearch(vector<int>& matrix, int target){
        int low = 0;
        int high = matrix.size()-1;
        while (low < high){
            int mid = low + (high-low)/2;
            if (matrix[mid] < target) low = mid + 1;
            else if (matrix[mid] > target) high = mid-1;
            else return mid;
        }
        return low;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //find row to search in
        int searchRow = binarySearch(matrix,target);
        int res = binarySearch(matrix[searchRow],target);
        return matrix[searchRow][res] == target;
    }
};

int main(){
    vector<vector<int>> inp{{1,2,2,3},{3,6,6,6},{23,30,34,60}};
    Solution solution;
    cout << solution.searchMatrix(inp,34);
}