class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int, int>>> adj_list(points.size());
        for(int i=0; i<points.size(); ++i) {
            for(int j=i+1; j<points.size(); ++j) {
                if(j == i) {
                    continue;
                }
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj_list[i].push_back({j, cost});
                adj_list[j].push_back({i, cost});
            }
        }       
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> min_heap;

        unordered_set<int> visited;
        min_heap.push({0, 0});
        int cost {0};
        while(true) {
            if(visited.size() >= points.size()) break;
            auto node = min_heap.top();
            min_heap.pop();
            if(visited.count(node.second)) continue;
            cost += node.first;
            cout<< "connected " << node.second << " " << node.first << endl;
            visited.insert(node.second);
            for(auto& nd: adj_list[node.second]) {
                if(not visited.count(nd.first)) {
                    min_heap.push({nd.second, nd.first});
                }
            }
        }
        return cost;

    }
};
