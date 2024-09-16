#include "Debug.cpp"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (fast != slow){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;
        while (fast != slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main(){
    Solution solution;
    vector<int> inp {1,3,4,2,2};
    solution.findDuplicate(inp);
}