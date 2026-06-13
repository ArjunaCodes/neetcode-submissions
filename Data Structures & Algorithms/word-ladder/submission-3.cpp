class Solution {
public:
    int min_count = INT_MAX;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool end_present = false;
        for(const auto& word: wordList) {
            if(word == endWord) {
                end_present = true;
                break;
            }
        }
        if(not end_present) return 0;
        unordered_map<string, vector<string>> adj_list;
        int word_len = beginWord.size();
        queue<string> que;
        que.push(beginWord);
        unordered_set<string> pro;
        int count = 0;
        int reachable = false;
        while(not que.empty()) {
            int size = que.size();
            count++;
            bool brk = false;
            while(size--) {
                string word = que.front();
                if(word == endWord){
                    reachable = true;
                    brk = true;
                    break;
                }
                que.pop();
                for(int i=0; i<word_len; ++i) {
                    string temp_copy = word;
                    temp_copy[i] = '*';
                    for(const auto& wd: wordList) {
                        string tmp = wd;
                        tmp[i] = '*';
                        if(temp_copy == tmp) {
                            // adj_list[word].push_back(wd);
                            if(pro.count(wd) == 0){
                                pro.insert(wd);
                                que.push(wd);
                            }
                        }
                    }
                }
            }
            if(brk) break;
        }
        return reachable ? count : 0;
        // int count = 1;
        // unordered_set<string> visited;
        // dfs(beginWord, endWord, adj_list, visited, count);
        // return min_count == INT_MAX ? 0 : min_count;
    }
    bool dfs(string& beginWord, string& endWord, unordered_map<string, vector<string>> adj, unordered_set<string> visited, int& count) {
        if(count > min_count) return false;
        if(beginWord == endWord)
        {
            min_count = min(count, min_count);
            return true;
        }
        visited.insert(beginWord);
        for(auto& word: adj[beginWord]) {
            if(visited.count(word) == 0) {
                // cout<< "word " << word << " count " << count << endl;
                dfs(word, endWord, adj, visited, ++count);
                --count;    
            }
        }
        return false;
    }
};
