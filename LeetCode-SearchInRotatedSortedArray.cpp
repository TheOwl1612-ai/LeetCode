#include "Debug.cpp"


class Solution {
public:
    int search(vector<int>& nums, int target) {
        //find min
        int low = 0;
        int high = nums.size()-1;
        while (low < high){
            int mid = low+(high-low)/2;
            if(nums[mid] < nums[high]) high = mid;
            else low = mid+1;
        }
        cout << nums[low];

        if (target == nums[low]) return low;
        if (target > nums[nums.size()-1]) high = low, low = 0;
        else high = nums.size()-1;

        while (low <= high){
            int mid = low+(high-low)/2;
            if (nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid+1;
            else high = mid-1;
        }

        return -1;

    }
};

int main(){
    Solution solution;
    vector<int> inp {1,3};
    solution.search(inp,3);
}