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
/*Debug funtions*/

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
int main(){
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};


    unordered_map<int,int> in_arr2{};
    vector<int> excl_arr1{};
    vector<int> result;
    /*add elements in arr1 that are in arr2 in the hash map*/
    for(int val : arr2){
        in_arr2[val] = 0;
    }

    /*count the elements in arr2 that are in arr1*/
    for (int i : arr1){
        if (in_arr2.find(i)==in_arr2.end()){
            excl_arr1.push_back(i);
        }
        else{
            in_arr2[i]++;
        }
    }
    sort(excl_arr1.begin(),excl_arr1.end());
    


    for(int j : arr2){
        for(int k = 0; k < in_arr2[j]; k++){
            result.push_back(j);
        }
    }
    for(int k : excl_arr1){
        result.push_back(k);
    }
    /*create a map to store counts of elements in arr2 that are in arr1
    overwrite the end of arr1 with elements that are exclusively in arr 1*/
    print(in_arr2);
    print(result);
};
