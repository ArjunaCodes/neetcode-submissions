class Solution {
public:
    void solve(vector<vector<char>>& board) {

        for(int i=0; i<board.size(); ++i) {
            for(int j=0; j<board[0].size(); ++j) {
                if(board[i][j] == 'O'){
                    vector<vector<bool>> region(board.size(), vector<bool>(board[0].size(), false));
                    bool is_valid = true;
                    find_adjacent_regions(i, j, board, region, is_valid);
                    for(int i=0; i<board.size(); ++i) {
                        for(int j=0; j<board[0].size(); ++j) {
                            if(region[i][j]) {
                                if (is_valid)
                                    board[i][j] = 'X';
                                else
                                    board[i][j] = 'y';
                            }
                        }
                    }
                }
            }
        }
        for(int i=0; i<board.size(); ++i) {
            for(int j=0; j<board[0].size(); ++j) {
                if(board[i][j] == 'y') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void find_adjacent_regions(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& region, bool& is_valid) {
        if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size()) {
            return;
        }
        if(board[i][j] == 'X' or board[i][j] == 'x' or region[i][j]) return;

        if(i == 0 or j == 0 or i == board.size()-1 or j == board[0].size()-1) {
                is_valid = false;
        }
        region[i][j] = true;

        find_adjacent_regions(i+1, j, board, region, is_valid);
        find_adjacent_regions(i, j+1, board, region, is_valid);
        find_adjacent_regions(i-1, j, board, region, is_valid);
        find_adjacent_regions(i, j-1, board, region, is_valid);
    }
};
