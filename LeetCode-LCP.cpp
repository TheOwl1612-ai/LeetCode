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
    vector<string> strs;
    string inp;
    stringstream aux;
    string word;
    getline(cin,inp);
    aux << inp;
    while (aux >> word){
        strs.push_back(word);
    }
    string prefix = strs[0];
    for (string i : strs){
        while (i.find(prefix) != 0){
            prefix = prefix.substr(0, prefix.size()-1);
            if (prefix.empty()){
                cout << "" << endl;
                break;
                return 0;
            }
        }
    }
    cout << prefix;
    return 0;
}
