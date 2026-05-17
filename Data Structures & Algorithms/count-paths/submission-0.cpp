class Solution {
    int path_count = 0;
public:
    void uniquePaths(int startx, int starty, int m, int n){
        if(startx == m and starty == n) {
            path_count++;
            return;
        }
        if(startx > m or starty > n) return;
        uniquePaths(startx + 1, starty, m, n);
        uniquePaths(startx, starty + 1, m, n);
    }
    int uniquePaths(int m, int n) {
        uniquePaths(1, 1, m, n);
        return path_count;
    }
};
