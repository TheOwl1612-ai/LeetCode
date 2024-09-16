#include <iostream>
#include <vector>
#include "Debug.cpp"
using namespace std;

class Solution {
public:
    int sumSquare(int n){
        int res = 0;
        while (n){
            res += (n%10)*(n%10);
            n = n / 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do{
            slow = sumSquare(slow);
            fast = sumSquare(fast);
            fast = sumSquare(fast);
            if (fast == 1)
                return true;
        }   
        while (slow != fast);
        return false;
    }
};

int main(){
    Solution solution;
    cout << solution.isHappy(2);

}