class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1. Build adjacency list (using size n + 1 because nodes are 1-indexed)
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }

        // 2. Initialize distance vector with infinity
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0; // Signal starts at node k

        // 3. Min-Priority Queue stores pairs of {accumulated_time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [current_time, u] = pq.top();
            pq.pop();

            // If we found a shorter path to u already, skip processing
            if (current_time > dist[u]) continue;

            // Explore neighbors
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // Relaxation step
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // 4. Find the maximum time out of all reachable nodes
        int max_delay = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1; // Node i is unreachable
            max_delay = max(max_delay, dist[i]);
        }

        return max_delay;
    }
};
