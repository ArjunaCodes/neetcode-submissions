class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size = matrix.size();
        int col  = matrix[0].size();
        // search which row has target;
        int i = 0;
        for(; i<size; ++i) {
            if(matrix[i][col-1] >= target) {
                if(i >= size) return false;
                int left = 0;
                int right = col-1;
                while(left <= right) {
                    int mid = left + ((right - left) / 2);
                    if(matrix[i][mid] == target) return true;
                    else if(matrix[i][mid] > target) right = mid -1;
                    else left = mid + 1;
                }
            }
        }
        return false;
    }
};
