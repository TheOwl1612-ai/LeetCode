#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int FindMax(vector<int> arr){
    int output = INT_MIN;
    for(int i : arr) 
        output = max(output,i);

    return output;
}


vector<int> CountingSort(vector<int> arr){
    int Max = FindMax(arr);
    vector<int> CountingArray (Max+1,0);
    for(int i : arr)
        CountingArray[i]++;
    
    vector<int> output;
    for (int i = 0; i < Max+1; i++)
        while( CountingArray[i] > 0){
            output.push_back(i);
            CountingArray[i]--;
        }
    return output;
}


void print(vector<int> arg){
    for (int foo : arg)
        cout << foo << " ";
    cout << endl;
}
void print(vector<vector<int>> arg){
    for (int i = 0; i < arg.size(); i++){
        cout << i << ": ";
        print(arg[i]);
    }
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count; // pair of value : frequency
        vector<int> temp {};
        vector<vector<int>> freq(nums.size()+1,temp); //index represents frequency, value represents numbers that have said frequency
        vector<int> res;


        for (int i : nums)
            if (count.find(i) == count.end()) //if the current number doesn't exist in the count map
                count[i] = 1;
            else
                count[i]++;

        for (auto pair : count)
            freq[pair.second].push_back(pair.first);

        for (int i = freq.size()-1; i >= 0; i--){
            for (int j : freq[i]){
                res.push_back(j);
                if (res.size() >= k) return res;
            }
        }
        return res;
    }
};

int main(){
    vector<int> inp {1,1,1,2,2,3,3,3,3};
    Solution solution;
    print(solution.topKFrequent(inp,2));
}