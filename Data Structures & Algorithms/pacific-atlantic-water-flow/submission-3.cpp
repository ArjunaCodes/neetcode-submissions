class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int col_size = heights[0].size();
        int row_size = heights.size();
        vector<vector<bool>> pacific(row_size, vector<bool>(col_size));
        vector<vector<bool>> atlantic(row_size, vector<bool>(col_size));
        for(int i=0; i<col_size; ++i) {
            dfs(heights, 0, i, pacific, heights[0][i]);
            dfs(heights, row_size-1, i, atlantic, heights[row_size-1][i]);
        }
        for(int j=0; j<row_size; ++j) {
            dfs(heights, j, 0, pacific, heights[j][0]);
            dfs(heights, j, col_size-1, atlantic, heights[j][col_size-1]);
        }
        vector<vector<int>> result;
        for(int i=0; i<row_size; ++i) {
            for(int j=0; j<col_size; ++j) {
                if(pacific[i][j] and atlantic[i][j]){
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited,int prev_land) {
        if(i < 0 or j < 0 or i >= heights.size() or j>= heights[0].size()) return;
        if(visited[i][j]) return;
        if(heights[i][j] < prev_land) return;
        visited[i][j] = true;
        dfs(heights, i+1, j, visited, max(prev_land, heights[i][j]));
        dfs(heights, i-1, j, visited, max(prev_land, heights[i][j]));
        dfs(heights, i, j+1, visited, max(prev_land, heights[i][j]));
        dfs(heights, i, j-1, visited, max(prev_land, heights[i][j]));
    }
};
