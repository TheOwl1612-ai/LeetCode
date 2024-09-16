#include "Debug.cpp"
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        unordered_map<char, char> map2;
        for (int i = 0; i < t.size(); ++i){
            if (!map.count(t[i])) 
                map[t[i]] = s[i];
            if (!map2.count(s[i])) 
                map2[s[i]] = t[i];
            if (map[t[i]] != s[i] || map2[s[i]] != t[i])
                return false;
        }
        return true;
    }
};
int main(){
    Solution solution;
    cout <<solution.isIsomorphic("foo","bar");
}