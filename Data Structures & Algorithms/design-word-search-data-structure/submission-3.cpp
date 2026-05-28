class WordDictionary {
public:
    struct trie {
        trie* childs[26];
        trie(): is_end_of_word{false} {
            for(int i=0; i < 26; ++i) {
                childs[i] = nullptr;
            }
        }
        bool is_end_of_word;
    };
    trie* root;
    WordDictionary() {
        root = new trie();
    }
    
    void addWord(string word) {
        trie* curr = root;
        for(auto ch: word) {
            int index = ch - 'a';
            if(not curr->childs[index]){
                curr->childs[index] = new trie();
            }
            curr = curr->childs[index];
        }
        curr->is_end_of_word = true;
    }
    
    bool search(string word, trie* prev = nullptr) {
        return advanced_search(word, 0, root);
    }
    bool advanced_search(string word, int index, trie* curr) {
        // if(not curr) return false;
        for(int i = index; i<word.size(); ++i) {
            if(word[i] == '.'){
                bool result = false;
                for(int l=0; l<26; ++l) {
                    if(curr->childs[l]){
                        result = advanced_search(word, i+1, curr->childs[l]);
                    }
                    if(result) return result;
                }
                return result;
            } else {
                if(not curr->childs[word[i] - 'a']) {
                    // std::cout<<word[i] << i << " " << (curr == root) <<endl;
                    return false;
                }
                // std::cout<<word[i] << " " << i << " " << (curr == root) <<endl;
                curr = curr->childs[word[i] - 'a'];
            }
        }
        // std::cout<<word<<endl;
        return curr->is_end_of_word;
    }
};
