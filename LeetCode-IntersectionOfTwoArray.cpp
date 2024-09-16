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


vector<int> Intersection(){
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,8,9,8,4};
    vector<int> result;
    unordered_map<int,bool> hash;
    for (int i : nums1){
        hash[i] = true;
    }
    for(int j : nums2){
        if (hash.find(j)!=hash.end()){
            hash[j] = false;
        }
    }

    for (auto key : hash){
        if (key.second == false){
            result.push_back(key.first);
        }
    }


    return result;
}

int main(){
    print(Intersection());




}