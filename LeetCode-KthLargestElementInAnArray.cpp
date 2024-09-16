#include "Debug.cpp"
class Solution {
public:
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int, vector<int>, greater<int>> pq;
    //     for (int i = 0; i < nums.size(); i++){
    //         pq.push(nums[i]);
    //         if (pq.size() > k) pq.pop();
    //     }
    //     return pq.top();
    // }
    int findKthLargest(vector<int>& nums, int k){
        return quickSelect(nums,0,nums.size()-1,nums.size()-k);
    }
private:
    int quickSelect(vector<int>& nums, int l, int r, int k){
        int p = l;
        for (int i = l; i < r; i++){
            if (nums[i] <= nums[r]) swap(nums[i],nums[p]), p++;
        }
        swap(nums[r],nums[p]);
        if (p > k) return quickSelect(nums,l,p-1,k);
        else if (p < k) return quickSelect(nums,p+1,r,k);
        return nums[p];
    }
};


int main(){
    Solution solution;
    vector<int> vect {3,2,1,5,6,4};
    int k = 2;
    solution.findKthLargest(vect,k);
}