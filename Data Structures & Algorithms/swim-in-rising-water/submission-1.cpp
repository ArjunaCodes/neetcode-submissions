class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0,0}});
        int n = grid.size();
        int max_so_far {0};
        while(true) {
            auto node = pq.top();
            pq.pop();
            int i = node.second.first;
            int j = node.second.second;
            if(visited[i][j]){
                continue;
            }
            visited[i][j] = true;
            max_so_far = max(max_so_far, node.first);
            if(i == n-1 and j == n-1) return max_so_far;
            if(j>0 and not visited[i][j-1]) pq.push({grid[i][j-1], {i, j-1}});
            if(i>0 and not visited[i-1][j]) pq.push({grid[i-1][j], {i-1, j}});
            if(j < n-1 and not visited[i][j+1]) pq.push({grid[i][j+1], {i, j+1}});
            if(i < n-1 and not visited[i + 1][j]) pq.push({grid[i+1][j], {i+1, j}});
         }
    }
};
