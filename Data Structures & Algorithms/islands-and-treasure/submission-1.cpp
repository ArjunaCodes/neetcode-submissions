class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>> tresures;
        for(int i=0; i<row; ++i) {
            for(int j=0; j<col; ++j) {
                if(grid[i][j] == 0) {
                    tresures.push({i, j});
                }
            }
        }
        vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(not tresures.empty()) {
            auto [i, j] = tresures.front();
            tresures.pop();
            for(auto [x, y]: directions) {
                x = i + x;
                y = j + y;
                if(x < 0 or y < 0 or x >= grid.size() or y >= grid[0].size() or grid[x][y] != 2147483647) {
                    continue;
                }
                grid[x][y] = grid[i][j] + 1;
                tresures.push({x, y});
            }
        }
    }
};
