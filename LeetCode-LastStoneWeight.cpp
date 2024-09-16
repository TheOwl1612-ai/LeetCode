#include <vector>
#include "Debug.cpp"

void helperHeapify(vector<int>& stones,int i){
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;
    int largest = i;
    if (leftChild < stones.size() && stones[leftChild] > stones[largest]) largest = leftChild;
    if (rightChild < stones.size() && stones[rightChild] > stones[largest]) largest = rightChild;

    if (i == largest) return;
    swap(stones[i],stones[largest]);
    helperHeapify(stones,largest); 
}
void heapifyDown(vector<int>& stones){
    for (int i = stones.size()-1; i >= 0; i--)
        helperHeapify(stones,i);
    
}
void heapifyUp(vector<int>& stones){
    int parent;
    int i = stones.size()-1;
    while (i >= 0){
        parent = (i-1)/2;
        if (stones[i] <= stones[parent]) return;
        swap(stones[i],stones[parent]);
        i = parent;
    }
}
int extractMax(vector<int>& stones){
    int res = stones.front();
    stones.front() = stones.back();
    stones.pop_back();
    heapifyDown(stones);
    return res;
}

void insert(vector<int>& stones, int data){
    stones.push_back(data);
    heapifyUp(stones);
}
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        heapifyDown(stones);
        while (stones.size() > 1){
            int y = extractMax(stones);
            int x = extractMax(stones);
            if (y != x) insert(stones,y-x);
        }
        if (stones.size() == 0) return 0;
        return stones[0];
    }

};

int main(){
    Solution solution;
    vector<int> stones = {2,7,4,1,8,1};
    int res = solution.lastStoneWeight(stones);
    cout << res;
}