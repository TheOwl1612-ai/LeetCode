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


int main(){
    string s;
    int result = 0;
    cin >> s;
    map<char,int> Romans;
    Romans['I'] = 1;
    Romans['V'] = 5;
    Romans['X'] = 10;
    Romans['L'] = 50;
    Romans['C'] = 100;
    Romans['D'] = 500;
    Romans['M'] = 1000; 
    /*
    XXVII = 10 + 10 + 5 + 1 + 1 = 27
    LVIII = 50 + 5 + 1 + 1 + 1 = 58
    MCMXCIV = 1000-100+1000-10+100-1+5 = 1994
    M = 1000
    C = 100, nhưng đứng trước M = 1000 nên -100
    M = 1000
    X = 10, nhưng đứng trước C = 100 nên -10
    C = 100
    I = 1, nhưng đứng trước V = 5 nên -1
    V = 5
    */
    for (int i = 0; i < s.size()-1; i++){
        if (Romans[s[i]] >= Romans[s[i+1]]){
            result += Romans[s[i]];
        }
        else{
            result -= Romans[s[i]];
        }
   }
    result += Romans[s[s.size()-1]];
    cout << result;
    return 0;
}
