class Solution {
public:
    struct trie {
        trie* childs[26] = {nullptr};
        string word = "";
    };
    trie* root;

    void create_trie(string word, trie* curr) {
        for(const auto& ch: word) {
            if(curr->childs[ch - 'a'] == nullptr) {
                curr->childs[ch - 'a'] = new trie();
            }
            curr = curr->childs[ch-'a'];
        }
        curr->word = word;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie* root = new trie();
        for(auto word: words) {
            create_trie(word, root);
        }
        vector<string> result;
        int row_size = board.size();
        int col_size = board[0].size();
        for(int i=0; i<row_size; ++i) {
            for(int j=0; j<col_size; ++j) {
                dfs_to_find(board, root, result, i, j);
            }
        }
        return result;
    }
    void dfs_to_find(vector<vector<char>>& board, trie* curr, vector<string>& result, int row, int col) {
        if(row < 0 or col < 0 or row >= board.size() or col >= board[0].size()) {
            return;
        }
        char copy = board[row][col];
        if(copy == '#' or not curr->childs[copy - 'a']) return;

        curr = curr->childs[copy - 'a'];

        if(curr->word != "") {
             result.emplace_back(curr->word);
             curr->word = "";
        }
        board[row][col] = '#';
        dfs_to_find(board, curr, result, row, col+1);
        dfs_to_find(board, curr, result, row+1, col);
        dfs_to_find(board, curr, result, row, col-1);
        dfs_to_find(board, curr, result, row-1, col);
        board[row][col] = copy;
    }
};
