#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>
using namespace std;
void print(vector<string> target){
    for (string s : target){
        cout << "s: " << s << " ";
    }
    cout << endl;
}
void print(unordered_map<string,vector<string>> a){
    for (auto i : a){
        cout << "Key: " << i.first << " ";
        print(i.second);
    }
    cout << endl;
}


string convertToString(vector<int> target){
    string result;
    for(int i : target){
        result += i + '0';
    }
    return result;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>> hash;
    vector<vector<string>> ans;

    for(string s : strs){
        vector<int> count (26, 0);
        for(char c : s){
            count[c-'a']++;
        }
        string temp = convertToString(count);
        hash[temp].push_back(s);
    }

    for (auto pair : hash){
        ans.push_back(pair.second);
    }
    return ans;
}
    
int main(){
    vector<string> input = {""};
    vector<vector<string>> anagram = groupAnagrams(input);
}

