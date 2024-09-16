#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string convert_to_str(int n){
    stringstream aux;
    string converted_n;
    aux << n;
    aux >> converted_n;
    return converted_n;
}
int main(){
    int x;
    cin >> x;
    string str_x = convert_to_str(x);
    int begin = 0;
    int end = str_x.size()-1;
    for (int i = end; i > -1; i--){
        if (str_x[i] != str_x[begin]){
            cout << false << endl;
            break;
        }
        begin++;
    }

}