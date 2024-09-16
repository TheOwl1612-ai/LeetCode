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
    stack<char> parentheses;
    string s;
    cin >> s;
    for (char c : s){
        if (c == '(' or c == '[' or c == '{'){
            parentheses.push(c);
        }
        else if (!parentheses.empty() and (c == ')' && parentheses.top() == '(' ||
                                           c == ']' && parentheses.top() == '[' ||
                                           c == '}' && parentheses.top() == '{')){
                parentheses.pop();
        }
        else{
            return false;
        }
    }
    return parentheses.empty();
}
