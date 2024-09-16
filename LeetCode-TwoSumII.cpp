#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target){
    unordered_map<int,int> hash;
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++){
        int complement = target-numbers[i];
        if (hash.find(complement) != hash.end()){
            result.push_back(hash[complement]+1);
            result.push_back(i+1);
            break;
        }
        hash[numbers[i]] = i;
    }
    return result;
}

int main(){
    vector<int> input = {-5,-4,0,2,9,12};
    vector<int> result = twoSum(input,8);
    for (int i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}