#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

void print(unordered_map<char,int> arg){
    for (auto item : arg){
        cout << "char: " << item.first << " " << "index: " << item.second << endl;
    }
    cout << endl;
}
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = INT_MIN;
        int i = 0;
        unordered_map<char,int> map; //character : its index

        for (int j = 0; j < s.size(); j++){
            if (map.find(s[j]) != map.end()){
                i = max(i,map[s[j]]+1);
            }    
            map[s[j]] = j;
            maxLength = max(maxLength, j-i+1);   
        }

        if (maxLength == INT_MIN)
            return s.size();

        return maxLength;
    }
};

int main(){

    Solution solution;
    cout << solution.lengthOfLongestSubstring("abba");
}