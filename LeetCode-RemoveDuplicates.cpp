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
    for (int i: a){
        cout << i << ' ';
    }
    cout << endl;
}
int main(){
    vector<int> nums;
    string s_input;
    stringstream ss_input;
    int num;
    getline(cin, s_input);
    ss_input << s_input;
    while (ss_input >> num){
        nums.push_back(num);
    }
    
    int r = 1;
    for (int l = 1; l < nums.size(); l++){
        if (nums[l] != nums[l-1]){
            nums[r] = nums[l];
            r++; 
        }
    }
    cout << r;
    return 0;

}

