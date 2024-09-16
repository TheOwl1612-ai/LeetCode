#include "Debug.cpp"
class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        map<int,double> m;

        for (int i = 0; i < pos.size(); i++) m[-pos[i]] = (double)(target-pos[i])/speed[i];

        int res = 0;
        double cur = 0;
        for (auto car : m)
            if (car.second > cur) cur = car.second, res++;
        return res;
    }
};

int main(){

}