#include "Debug.cpp"
class Solution {
public:
    unordered_map<int,vector<int>> graph {};
    vector<int> visited;
    vector<int> res {};

    bool dfs(int node){
        if (visited[node] == 1) return false; //visited but not done
        if (visited[node] == 2) return true; //done

        visited[node] = 1;
        for (int neighbor: graph[node]){
            if (!dfs(neighbor)) return false;
        }
        visited[node] = 2;
        res.push_back(node);
        return true;
    }



    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //init the graph
        visited = vector<int> (numCourses);

        for (auto pre : prerequisites){
            graph[pre[0]].push_back(pre[1]);
        }

        for (int i = 0; i < numCourses; i++){
            if (visited[i] == 0) {
                if (!dfs(i)) return {};
            }
        }
        return res;
        
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> graph = {
        {0,1},
        {1,4},
        {4,3},
        {3,5}
    };

    // Use the `graph` variable as needed.
    print(solution.findOrder(1,graph));
    return 0;
}