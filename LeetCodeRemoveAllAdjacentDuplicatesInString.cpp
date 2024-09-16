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
void print(vector<int> a){
    for(int i : a){
        cout << i << " ";
    }
    cout << endl;
}
void print(unordered_map<int,bool> a){
    for (auto i : a){
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
void print(stack<int> target){
    string result = "";
    while (!target.empty()){

        result += to_string(target.top()) + " ";
        target.pop();
    }
    cout << result << endl;
}

string removeDuplicates(string s){
    stack<char> letters;
    string result = "";
    for (char& c : s)
        if (result.size() && c == result.back())
            result.pop_back();
        else
            result.push_back(c);
    return result;
    
}
int main(){
    cout << removeDuplicates("abbaca") << endl;
/*
abbaca
đẩy phần tử vào stack
a
ab
phần tử đang duyệt là b, thấy giống stack.top() nên stack.pop() và chuyển tiếp*/
    

}