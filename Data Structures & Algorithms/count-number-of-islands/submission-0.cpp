class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        unordered_map<int, unordered_set<int>> visited_land;
        int row_size = grid.size();
        int col_size = grid[0].size();
        int island_count = 0;
        for(int i=0; i<row_size; ++i) {
            for(int j=0; j<col_size; ++j) {
                if(grid[i][j] == '1' and visited_land[i].find(j) == visited_land[i].end()) {
                    island_count ++;
                    explore_islands(grid, i, j, visited_land);
                }
            }
        }
        return island_count;
    }
    void explore_islands(vector<vector<char>>& grid, int i, int j, unordered_map<int, unordered_set<int>>& visited) {
        if(i<0 or j<0 or i >= grid.size() or j>=grid[0].size()) {
            return;
        }
        if(visited[i].find(j) != visited[i].end() or grid[i][j] != '1') return;
        visited[i].insert(j);
        explore_islands(grid, i+1, j, visited);
        explore_islands(grid, i, j+1, visited);
        explore_islands(grid, i-1, j, visited);
        explore_islands(grid, i, j-1, visited);
    }
};
