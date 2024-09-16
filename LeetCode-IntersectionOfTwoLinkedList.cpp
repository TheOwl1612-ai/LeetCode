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



ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
    ListNode* travelA = headA;
    ListNode* travelB = headB;
    while(travelA != travelB){
        travelA = travelA -> next;
        travelB = travelB -> next;
        if(travelA == nullptr && travelB == nullptr){
            return travelA;
        }
        if (not travelA){
            travelA = headB;
        }
        if(not travelB){
            travelB = headA;
        }
    }
    return travelA;   
}
int main(){
    ListNode* a1 = new ListNode(4);
    ListNode* a2 = new ListNode(1);
    ListNode* b1 = new ListNode(5);
    ListNode* b2 = new ListNode(6);
    ListNode* b3 = new ListNode(1);
    ListNode* i1 = new ListNode(8);
    ListNode* i2 = new ListNode(4);
    ListNode* i3 = new ListNode(5);
    a1 -> next = a2;
    b1 -> next = b2;
    b2 -> next = b3;


    a2 -> next = i1;
    b3 -> next = i1;
    i1 -> next = i2;
    i2 -> next = i3;


    cout << getIntersectionNode(a1,b1) -> val;
    








}