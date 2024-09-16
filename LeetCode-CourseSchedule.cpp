#include "Debug.cpp"

class Solution {
public:
    unordered_map<int,vector<int>> graph {};
    vector<int> visited;

    bool dfs(int node){
        if (visited[node] == 1) return false; //visiting
        if (visited[node] == 2) return true; //visited

        visited[node] = 1;
        for (int neighbor: graph[node]){
            if (!dfs(neighbor)) return false;
        }
        visited[node] = 2;
        return true;
    }



    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //init the graph
        visited = vector<int> (numCourses);
        if (prerequisites.empty()) return true;
        for (auto pre : prerequisites){
            graph[pre[0]].push_back(pre[1]);
        }

        for (int i = 0; i < numCourses; i++){
            if (visited[i] == 0) {
                if (!dfs(i)) return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> matrix = {
    {1, 0},
    {0,2},
    {2,3},
    {4,3},
};
    cout << solution.canFinish(4,matrix);

}