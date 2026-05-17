class Solution {
public:
    bool isValidRow(vector<vector<char>>& board, int row) {
        vector<bool> values(9, false);
        for(int i=0; i<9; ++i) {
            if(isdigit(board[row][i])) {
                if(values[board[row][i] - '0']) {
                    std::cout<< "row is invalid " << i << " " << row << endl;
                    return false;
                }
                values[board[row][i] - '0'] = true;
            }
        }
        return true;
    }
    bool isValidCol(vector<vector<char>>& board, int col) {
        vector<bool> values(9, false);
        for(int i=0; i<9; ++i) {
            if(isdigit(board[i][col])) {
                if(values[board[i][col] - '0']) {
                    std::cout<< "col is invalid " << i << " " << col << endl;
                    return false;
                }
                values[board[i][col] - '0'] = true;
            }
        }
        return true;
    }
    bool isValidCube(vector<vector<char>>& board, int row, int col){
        vector<bool> values(9, false);
        for(int i=row; i<row+3; ++i) {
            for(int j=col; j<col+3; ++j) {
                if(isdigit(board[i][j])) {
                    if(values[board[i][j] - '0']){
                        std::cout << "cube : " << row << " " << col << values[board[i][j]] << endl;
                        return false;
                    }
                    values[board[i][j] - '0'] = true;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; ++i){
            if(not isValidRow(board, i) or not isValidCol(board, i)) {
                std::cout<<"row or collum " << std::endl;
                return false;
            }
        }
        for(int i=0; i<9; i+=3) {
            for(int j=0; j<9; j+=3) {
                if(not isValidCube(board, i, j)){
                    std::cout<<"cube is not valid" << std::endl;
                    return false;
                }
            }   
        }
        return true;
    }
};
