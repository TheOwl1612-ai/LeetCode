#include "Debug.cpp"
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        vector<int>map (27,0);
        for (char c : s1)
            map[c-97]++; //fill map
        
        vector<int>currCharMap (27,0);
        size_t l1 = s1.size();

        //fill map with first l1 chars of s2, thus creating a window
        for (int i = 0; i < l1; i++)
            currCharMap[s2[i]-97]++;
        if (currCharMap == map) return true;

        //slide the window
        for (int left = 1; left < s2.size()-l1+1; left++){
            currCharMap[s2[left-1]-97]--;
            currCharMap[s2[left+l1-1]-97]++;
            if (currCharMap == map) return true;
        }    
        return false;
    }
};
int main(){
    Solution solution;
    cout << solution.checkInclusion("ab","eidboaoo");
}