#include "Debug.cpp"

class TimeMap {
public:
    map<string,map<int,string>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        const auto& it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" : prev(it)->second;
        /*nếu ite ở đầu thì tức là không có phần tử nào trong map có mốc thời gian bé hơn hoặc bằng mốc thời gian cần tìm*/
        /*ngược lại nếu ite ở giữa hoặc cuối thì có nghĩa là có phần tử trong map có mốc thời gian lớn nhất bé hơn hoặc bằng
        mốc thời gian cầm tìm*/
    }
};


int main(){

}