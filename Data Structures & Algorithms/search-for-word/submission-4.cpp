class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int col_size = board[0].size();
        int row_size = board.size();
        for(int i=0; i < row_size; ++i) {
            for(int j=0; j<col_size; ++j) {
                if(is_possible(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool is_possible(vector<vector<char>>& board, string& word, int index, int row, int col) {
        if(index >= word.size()) return true;
        if(row < 0 or col < 0 or row >= board.size() or col >= board[row].size()) return false;
        if(word[index] != board[row][col])return false;
        char back_up = board[row][col];
        board[row][col] = '#';

        bool possible =  is_possible(board, word, index+1, row, col+1) or
                is_possible(board, word, index+1, row+1, col) or
                is_possible(board, word, index+1, row, col-1) or
                is_possible(board, word, index+1, row-1, col);

        board[row][col] = back_up;
        return possible;
    }
};
