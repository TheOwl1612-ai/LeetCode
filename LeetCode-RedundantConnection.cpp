#include "Debug.cpp"

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size() + 1;
        vector<vector<int>> graph (n);


        for (const vector<int>& edge : edges){
            vector<bool> visited (n,false);
            int cur = edge[0];
            int child = edge[1];

            if (!graph[cur].empty() && !graph[child].empty() && dfs(graph,visited,cur,child)){
                return edge;
            }

            graph[cur].push_back(child);
            graph[child].push_back(cur);
        }

        return {};
    }

    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int cur, int target){
        if (cur == target) return true;
        if (visited[cur]) return false;

        visited[cur] = true;
        for (int child : graph[cur]){
            if (dfs(graph,visited,child,target)) return true;
        }
        return false;
    }
};

int main(){

}