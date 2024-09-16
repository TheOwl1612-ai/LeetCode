#include "Debug.cpp"

class Solution {
public:
    vector<string> res;
    int maxOpens;

    void generate(int open,int close, string currString){
        if (currString.size() == maxOpens*2){
            res.push_back(currString);
            return;
        }

        if (open > 0)
            generate(open-1,close+1,currString+'(');

        if (close > 0)
            generate(open,close-1,currString+')');

    }
    vector<string> generateParenthesis(int n) {
        maxOpens = n;
        generate(n,0,"");
        return res;
    }
};

int main(){
    Solution solution;
    solution.generateParenthesis(3);
}