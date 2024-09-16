#include "Debug.cpp"
class KthLargest {
public:
    /*stores first k elements in a queue
    if the k.front() <= new num <= k.back
    then add that number to the queue and remove a number from the queue, add it to the priority queue*/
    priority_queue<int,vector<int>,greater<int>> firstKs;
    priority_queue<int> pq;
    
    KthLargest(int k, vector<int>& nums): pq(nums.begin(), nums.end()) {
        firstKs = getFirstKs(pq,k);
    }
    
    int add(int val) {
        pq.push(val); 
        if (firstKs.empty()){ 
            firstKs.push(val); 
            return val;
        }
        if (val > firstKs.top()){ 
            firstKs.pop();
            firstKs.push(val);
        }
        return firstKs.top();

    }

private:
    priority_queue<int,vector<int>,greater<int>> getFirstKs(priority_queue<int> pq, int k){
        priority_queue<int, vector<int>, greater<int>> res;
        if (!pq.empty())
            for (int i = 0; i < k; i++){
                res.push(pq.top());
                pq.pop();
            }
        return res;
    }
};
int main(){
    int k = 1;
    vector<int> input = {};
    KthLargest stream(k,input);
    stream.add(-3);
    stream.add(-2);
    stream.add(-4);
    stream.add(0);
    stream.add(4);
}