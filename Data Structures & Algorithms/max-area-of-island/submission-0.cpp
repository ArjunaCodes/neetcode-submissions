class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_count = 0;
        for(int i=0; i<grid.size(); ++i) {
            for(int j=0; j<grid[0].size(); ++j) {
                int count = 0;
                if(grid[i][j] == 1) {
                    cout<<"hello" <<endl;
                    dfs(grid, i, j, count);
                }
                max_count = max(count, max_count);
            }
        }
        return max_count;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int& count) {
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size()) {
            return;
        }
        if(grid[i][j] != 1) {
            return;
        }
        grid[i][j] = 0;
        count++;
        cout<<count<<endl;
        dfs(grid, i+1, j, count);
        dfs(grid, i, j+1, count);
        dfs(grid, i-1, j, count);
        dfs(grid, i, j-1, count);
    }
};
