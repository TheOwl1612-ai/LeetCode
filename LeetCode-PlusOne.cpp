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
    for (int i : a){
        cout << i << ' ';
    }
    cout << endl;
}
int main(){
    /*
    1 2 1
    1 2 2
    1 -> 2 (condition false)
    
    1 8 9
    1 9 0
    9 -> 10 (condition true)
    8 -> 9

    [10,8+1]

    1 9 9
    2 0 0
    9->10 (condition true)
    9->10 (condition true)
    1->2  
    [9+1,9+1,1+1]
    */
    vector<int> digits = {9,9};
    //stack<int> conditions = {};
    bool condition = false;
    for (int i = digits.size()-1; i >= 0; i--){
        digits[i] += 1;
        if ((digits[i]) == 10){
            digits[i] = 0;
            condition = true;
        }
        else{
            condition = false;
            break;
        }
    }
    if (condition == true){
        digits.insert(digits.begin(),1);
    }
    print(digits);
};


