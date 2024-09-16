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
void print(unordered_map<ListNode*,int> a){
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




bool detect_circular(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast and fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if (fast = slow){
            return true;
        }
    }
    return false;
    
}



int main(){
    ListNode* Node1 = new ListNode(1);
    ListNode* Node2 = new ListNode(2);
    // ListNode* Node3 = new ListNode(0);
    // ListNode* Node4 = new ListNode(-4);
    
    Node1 -> next = Node2;
    Node2 -> next = Node1;


    cout << detect_circular(Node1);



    
}