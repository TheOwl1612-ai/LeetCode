#include <iostream>
#include <vector>
using namespace std;

bool isOdd(int& a){
    return a % 2 != 0;
}

bool ThreeConsecutiveOdds(vector<int>& arr){
    for (int i = 1; i < arr.size()-1; i++){
        if (isOdd(arr[i]) && isOdd(arr[i-1]) && isOdd(arr[i+1]))
            return true;
    }
    return false;
}

int main(){
    vector<int> test {1};
    cout << ThreeConsecutiveOdds(test);

}