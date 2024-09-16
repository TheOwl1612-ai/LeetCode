#include "Debug.cpp"

class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int,vector<int>>> pq;

        for (auto point : points){
            int distance = calcOrigin(point);
            pq.push({distance,point});
            if (pq.size() > k) pq.pop();
        }

        while (!pq.empty()){
            res.push_back(pq.top().second);
             pq.pop();
        }
        return res;
        
    }
    int calcOrigin(vector<int>& cords){
        return pow(cords[0],2) + pow(cords[1],2);
    }
};

int main(){
    Solution solution;
    vector<vector<int>> inp {{1,0},{0,1}};
    print(solution.kClosest(inp,2));
}