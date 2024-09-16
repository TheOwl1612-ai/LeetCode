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
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,4,5,0,0,0};
    int n = 3;

    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    while (j >= 0){
        if (i >= 0 and nums1[i] > nums2[j]){
            nums1[k--] = nums1[i--];
        }
        else{
            nums1[k--] = nums2[j--];
        }
    }
    print(nums1);
    return 0;
};
