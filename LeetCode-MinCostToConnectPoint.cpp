#include "Debug.cpp"
#include <numeric>
#define INF INT_MAX
class Solution {
public:
    typedef pair<int,int> point; //distance - node

    int calcDist(vector<int>& pointA, vector<int>& pointB){
        return (abs(pointA[0] - pointB[0]) + abs(pointA[1] - pointB[1]));
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        priority_queue<point,vector<point>, greater<point>> pq;
        vector<int> dist (V,INF);
        vector<bool> visited (V, false);

        dist[0] = 0;
        pq.push({0,0});

        while (!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            visited[u] = true;

            for (int v = 0; v < V; v++){
                int curDist = calcDist(points[u],points[v]);
                if (!visited[v] && dist[v] > curDist){
                    dist[v] = curDist;
                    pq.push({curDist,v});
                }
            }
        }

        //final result
        return accumulate(dist.begin(),dist.end(),0);
        
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> vec = {
    {3, 12},
    {-2, 5},
    {-4, 1}
};
    cout << solution.minCostConnectPoints(vec);
}