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

int calPoints(vector<string>& operations) {
    stack<int> record;
    stack<int> prev;
    int sum = 0;
    for(string s : operations){
        if(s == "C"){
            if(!prev.empty()){
                prev.pop();
            }
            sum -= record.top();
            record.pop();
            continue;
        }
        else if(s == "D"){
            prev.push(record.top());
            record.push(record.top()*2);
        }
        else if(s == "+"){
            int temp = record.top();
            record.push(record.top()+prev.top());
            prev.push(temp);
        }
        else{
            if(!record.empty()){
                prev.push(record.top());
            }
            record.push(stoi(s));
        }
        sum+=record.top();

    }
    cout << sum << endl;
    return sum;

}

int main(){
    vector<string> ops = {"36","28","70","65","C","+","33","-46","84","C"};

    calPoints(ops);



}