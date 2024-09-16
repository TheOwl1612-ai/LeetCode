#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
void print(vector<int> target){
    for(int i : target){
        cout << i << " ";
    }
    cout << endl;
}
void print(unordered_map<int,bool> target){
    for (auto i : target){
        cout << "Key: " << i.first << "  " << "Value: " << i.second << endl; 
    }
    cout << endl;
}
void print(ListNode* head){
    ListNode* current = head;
    while (current != nullptr){
        cout << current -> val << " ";
        current = current -> next;
    }
    cout << endl;
}
void print(stack<char> target){
    string result = "";
    while (!target.empty()){
        result += target.top();
        target.pop();
    }
    reverse(result.begin(),result.end());
    cout << result << endl;
}


/*()()()()*/

int main(){
    string s = "(()())(())(()(()))";
    /*
    đầu tiên là cứ đẩy vào phần tử
    nếu top là ')' thì pop 2 lần;
    nếu sau khi pop mà stack ko empty thì thêm 2 phần tử đó vào;
    */
    stack<char> pr;
    string result = "";
    for(char c : s){
        if(c == '('){
            if (!pr.empty()){
                result += c;
            }
            pr.push(c);
        }
        if(c == ')'){
            pr.pop();
            if(!pr.empty()){
                result += c;
            }
        }
    }
    cout << result << endl;




}