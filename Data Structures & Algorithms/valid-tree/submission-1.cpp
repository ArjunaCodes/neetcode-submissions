class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
      if (edges.size() != n - 1) return false;
        vector<vector<int>> graph(n);
        for(int i=0; i<edges.size(); ++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_set<int> visited;
        if(not dfs(visited, graph, 0, -1)) return false;

        return visited.size() == n;
    }
    bool dfs(unordered_set<int>& visited, vector<vector<int>>& graph, int node, int parent) {
        if (visited.count(node)) return false;
        visited.insert(node);
        for(auto n: graph[node]) {
            if(n == parent) continue;
            if (not dfs(visited, graph, n, node)) return false;
        }
        return true;
    }
};
