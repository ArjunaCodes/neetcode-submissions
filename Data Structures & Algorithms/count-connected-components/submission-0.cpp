class Solution {
public:
    void dfs(int node, unordered_set<int>& visited, vector<vector<int>>& adj_nodes) {
        if(visited.count(node)) return;
        visited.insert(node);
        for(auto n: adj_nodes[node]) {
            dfs(n, visited, adj_nodes);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_nodes(n);
        for(auto edge: edges) {
            adj_nodes[edge[0]].push_back(edge[1]);
            adj_nodes[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        int comp {0};
        for(int i=0; i<n; i++) {
            if(not visited.count(i)) {
                ++comp;
                dfs(i, visited, adj_nodes);
            }
        }
        return comp;
    }
};
