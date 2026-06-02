class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten;
        for(int i=0; i<grid.size(); ++i) {
            for(int j=0; j<grid[0].size(); ++j) {
                if(grid[i][j] == 2) {
                    rotten.push({i, j});
                }
            }
        }
        int time_taken = 0;
        vector<pair<int, int>> directions{{0,1}, {1,0}, {-1,0}, {0,-1}};
        while(not rotten.empty()) {
            int size = rotten.size();
            bool effective {false};
            while(size) {
                auto [i, j] = rotten.front();
                rotten.pop();
                for(auto [x, y]: directions) {
                    x += i;
                    y += j;
                    if(x<0 or y<0 or x >= grid.size() or y >= grid[0].size() or grid[x][y] != 1) continue;
                    grid[x][y] = 2;
                    rotten.push({x,y});
                    effective = true;
                }
                --size;
            }
            if(effective)
                time_taken++;
        }
        for(int i=0; i<grid.size(); ++i) {
            for(int j=0; j<grid[0].size(); ++j) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time_taken;
    }
};
// 2 2 2
// 2 2 0
// 0 4 5
