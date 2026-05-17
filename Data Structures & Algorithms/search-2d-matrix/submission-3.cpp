class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size = matrix.size();
        int col  = matrix[0].size();
        // search which row has target;
        int i = 0;
        int l = 0;
        int r = size * col - 1;
        while(l <= r) {
            int mid = l + ((r-l)/2);
            int row = mid / col;
            int colm = mid % col;
            if(target > matrix[row][colm]) {
                l = mid + 1;
            }
            else if ( target < matrix[row][colm]) {
                r = mid - 1;
            }
            else {
                 return true;
            }
        }
        return false;
    }
};
