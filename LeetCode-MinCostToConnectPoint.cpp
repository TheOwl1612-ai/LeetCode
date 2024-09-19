#include "Debug.cpp"
#include <numeric>
class Solution {
public:
    int calcDist(vector<int>& a, vector<int>& b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        size_t V = points.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //cost : index
        vector<bool> visited (V,false);

        int connected = 0;
        int first = 0;
        int res = 0;
        while (++connected < V){
            visited[first] = true;
            int second = first;
            for (int second = 0; second < V; second++){
                if (!visited[second]){
                    pq.push({calcDist(points[first],points[second]),second});
                }
            }

            while (visited[pq.top().second]){
                pq.pop();
            }

            res += pq.top().first;
            first = pq.top().second;
            pq.pop();
        }

        return res;
        
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> points = {
        {0, 0},
        {2, 2},
        {3, 10},
        {5, 2},
        {7, 0}
    };
    cout << solution.minCostConnectPoints(points);
};
