#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(vector<string> arg){
    for (string foo : arg){
        cout << foo << endl;
    }
}


class Solution {
public:
    vector<vector<char>> map {{},{},
                              /*2*/ {'a','b','c'},
                              /*3*/ {'d','e','f'},
                              /*4*/ {'g','h','i'},
                              /*5*/ {'j','k','l'},
                              /*6*/ {'m','n','o'},
                              /*7*/ {'p','q','r','s'},
                              /*8*/ {'t','u','v'},
                              /*9*/ {'w','x','y','z'}};
    vector<string> res;
    void backtrack(int first, string digits, string currString){
        if (currString.size() == digits.size() && !currString.empty()){
            res.push_back(currString);
            return;
        }

        vector<char> currChars = map[digits[first]-'0'];
        for (char c : currChars){
            currString += c;
            backtrack(first+1,digits,currString);
            currString.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {        
        if (digits.empty())
            return {};
        backtrack(0,digits,"");
        return res;
    }
};

int main(){
    Solution solution;
    solution.letterCombinations("2");
    
}