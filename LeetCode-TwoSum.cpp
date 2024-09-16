#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    //Input
    vector<int> nums;
    string s_inp;
    getline(cin,s_inp);
    stringstream ss_inp;
    ss_inp << s_inp;

    int int_inp;
    char dump;

    while (ss_inp >> int_inp){
        nums.push_back(int_inp);
    }

    int target;
    cin >> target;
    unordered_map <int,int> hash_table;
    for (int j = 0; j < nums.size(); j++){
        hash_table[nums[j]] = j;
        int complement = target - nums[j];
        if (hash_table.find(complement) != hash_table.end()){
            if (j < hash_table[complement]){
                cout << j << ' ' << hash_table[complement] << endl;
            }
            else{
                cout << hash_table[complement] << ' ' << j << endl;
            }
            break;
        }
        else{
            hash_table[nums[j]] = j;
        }
    }
}


