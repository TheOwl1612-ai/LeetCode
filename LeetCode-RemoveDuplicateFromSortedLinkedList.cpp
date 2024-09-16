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
void print(vector<int> a){
    for(int i : a){
        cout << i << " ";
    }
    cout << endl;
}

void print(unordered_map<int,int> a){
    for (auto i : a){
        cout << "Key: " << i.first << "  " << "Value: " << i.second << endl; 
    }
    cout << endl;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

void print(ListNode* head){
    ListNode* current = head;
    while (current != nullptr){
        cout << current -> val << " ";
        current = current -> next;
    }
    cout << endl;
}

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr){
        return head;
    }
    if (head -> next == nullptr){
        return head;
    }

    ListNode* curr = head;
    ListNode* prev = head;
    while(curr != nullptr){
        if (curr -> val != prev -> val){
            prev -> next = curr;
            prev = prev -> next;
        }
        curr = curr -> next;
    }
    prev -> next = nullptr;
    return head;
}


int main(){
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(3);
    ListNode* third = new ListNode(4);
    ListNode* fourth = new ListNode(5);
    ListNode* fitth = new ListNode(5);


    first -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fitth;

    ListNode* result = deleteDuplicates(first);
    
}