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
int main(){
    vector<int> nums = {2,2,1};
    int ans = 0;
    for(int i : nums){
        ans^=i;
    }
    cout << ans;
};
