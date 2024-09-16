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
int BinarySearch(int key){
    if (key == 0 or key == 1){
        return key;
    }
    int low = 0;
    int high = key;
    long long mid;
    while (low <= high){
        mid = low+(high-low)/2;
        if (mid*mid == key){
            return mid;
        }
        else if(mid*mid > key){
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }
    return high;
}
int main(){
    int x;
    cin >> x;
    cout << BinarySearch(x);
};
/*1 2 3 4 5
mid = 3*/