#include "Debug.cpp"
class Solution {
public:
    unordered_map<char,int> map;
    int findMax(){
        int res = 0;
        for (auto item : map){
            res = max(res,item.second);
        }
        return res;
    }
    int characterReplacement(string s, int k) {
        int res = 0;
        int l = 0;
        for (char c : s) map[c] = 0;
        for (int r = 0; r < s.size(); r++){
            map[s[r]]++;
            while (r-l+1 - findMax() > k){
                map[s[l]]--; 
                l++;
            }
            res = max(res,r-l+1); 
        }
        return res;
    }
};

int main(){
    Solution solution;
    cout << solution.characterReplacement("BCC",1);
}