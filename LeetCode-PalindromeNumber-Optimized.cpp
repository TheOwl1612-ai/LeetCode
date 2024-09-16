#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    /*Ex: x = 12121
    a = 0
    Tách số 1 ở hàng đơn vị:
    a += 1
    x = 1212 = (12121-1)/10 = (x-a)/10
    Tách số 2 ở hàng đơn vị:
    a = 12 = a*10 + 2
    x = 121 = (1212-2)/10 = (x-a)/10
    Bỏ số 1 ở cuối x
    a = 12
    x = 12 = (121-1)/10
    a = x 
    -> palindrome
    Ex : x = 1221
    Bỏ số 1 ở hàng đơn vị
    a = 1
    x = 122
    Bỏ số 2 ở hàng đơn vị
    a = 12
    x = 12
    a = x
    -> palindrome
    Xử lí vòng lặp cho số chẵn và lẻ:
    thử: end loop khi a > x:
    1456
    a = 65 > b = 41
    
    1551
    a = 15 == b = 15 (break)
    Edge cases: x < 0 or x % 10 == 0*/
    int x;
    int a = 0; //second half of x
    cin >> x;
    if (x >= 0 and x < 10){
        cout << true << endl;
    }
    else if(x % 10 == 0){
        cout << true << endl;
    }
    else{
        while (x>a){
            a = a*10 + x % 10;
            x = (x-x%10)/10;
            if (a == x){
                cout << true << endl;
                return 0;
            }
        }
        if (a/10 == x){
            cout << true << endl;
        }
        else{
            cout << false << endl;
            return 0;
        }
    }

}


