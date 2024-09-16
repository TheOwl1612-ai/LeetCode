#include "Debug.cpp"
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token:tokens){
            if (token != "+" && token != "-" && token != "/" && token != "*"){
                st.push(stoi(token));
                continue;
            }
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if (token == "+"){
                st.push(a+b);
            }
            else if(token == "-"){
                st.push(a-b);
            }
            else if(token == "/"){
                st.push(b/a);
            }
            else{
                st.push(a*b);
            }
        }
        return st.top();
    }
};

int main(){
    Solution solution;
    vector<string> inp {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << solution.evalRPN(inp);
}