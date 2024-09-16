#include "Debug.cpp"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0;
        int r = 1000000000;
        while (l < r){
            int m = l + (r-l)/2;
            int total = 0;
            for (int p : piles){
                total+=(p+m-1)/m;
            }
            if (total > h) l = m+1;
            else r = m-1;
        }      
        return l;
    }
};