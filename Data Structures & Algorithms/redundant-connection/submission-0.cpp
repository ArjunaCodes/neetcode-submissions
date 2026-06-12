class Solution {
public:
    // Helper function to find the root parent of a node (with path compression)
    int findRoot(int i, vector<int>& parent) {
        if (parent[i] == i)
            return i;
        return parent[i] = findRoot(parent[i], parent); // Path compression
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        
        // Initially, every node is its own parent
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // Process edges one by one in their original input order
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int rootU = findRoot(u, parent);
            int rootV = findRoot(v, parent);

            // If they share the same root, adding this edge creates a cycle!
            if (rootU == rootV) {
                return edge; // This is guaranteed to be the last edge causing the cycle
            }

            // Otherwise, union the two sets
            parent[rootU] = rootV;
        }

        return {};
    }
};
