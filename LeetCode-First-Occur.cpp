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
    string haystack;
    string needle;
    cin >> haystack;
    cin >> needle;
    string aux = "";
    int first_occur;
    for (int i = 0; i < haystack.size(); i++){
        aux += haystack[i];
        if (aux.size() > needle.size()){
            aux.erase(aux.begin());
            first_occur = i-needle.size()+1;
        }
        cout << aux << endl;
        if (aux == needle){
            cout << first_occur << endl;
            return 0;
        }
    }
};

