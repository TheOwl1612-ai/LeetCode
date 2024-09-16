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
void print(queue<int> target){
    while (!target.empty()){
        cout << target.front() << " ";
        target.pop();
    }
    cout << endl;
        
}



int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int ones = 0;
    int zeros = 0;
    for(int i = 0; i < students.size(); i++){
        if (students[i] == 0)
            zeros++;
        else
            ones++;
    }

    for(int i : sandwiches){
        if (i == 0){
            if (zeros == 0) return ones;
            zeros--;
        }
        else{
            if (ones == 0) return zeros;
            ones--;
        }
    }   
    return 0;

}
int main(){
    vector<int> students = {1,0,1,1};
    vector<int> sandwiches = {0,1,0,1};
    cout << countStudents(students,sandwiches) << endl;

}   