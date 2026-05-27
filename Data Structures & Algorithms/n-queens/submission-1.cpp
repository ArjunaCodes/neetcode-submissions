class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> queen(n, vector<bool>(n, false));
        vector<vector<string>> result;
        form_n_queens(n, queen, result, 0);
        return result;
    }
    void form_n_queens(int n, vector<vector<bool>>& queen, vector<vector<string>>& result, int row) {
        if(row >= n) {
            result.push_back(create_string_form(queen));
            return;
        }
        // for(int i=row; i<n; ++i) {
            for(int col=0; col<n; ++col) {
                if(valid_to_insert(queen, n, row, col)) {
                    queen[row][col] = true;
                    form_n_queens(n, queen, result, row+1);
                    queen[row][col] = false;
                }
            }
        // }
    }
    bool valid_to_insert(vector<vector<bool>> queen, int n, int row, int col){
        for(int i=0; i<n; ++i) {
            if(queen[row][i] or queen[i][col]) {
                return false;
            }
            if((row-i >= 0) and (col-i >= 0)) {
                if(queen[row-i][col-i]) {
                    return false;
                }
            }
            if((row+i < n) and (col+i < n)) {
                if(queen[row+i][col+i]) {
                    return false;
                }
            }
            if((row-i >= 0) and (col+i < n)) {
                if(queen[row-i][col+i]) {
                    return false;
                }
            }
            if((row+i < n) and (col-i >= 0)) {
                if(queen[row+i][col-i]) {
                    return false;
                }
            }
        }
        return true; 
    }
    vector<string> create_string_form(vector<vector<bool>>& queen) {
        vector<string> res;
        string result;
        for(auto vec: queen) {
            for(auto val: vec) {
                if(val)
                    result += "Q";
                else
                    result += ".";
            }
            res.emplace_back(result);
            result = "";
        }
        return res;
    }
};
