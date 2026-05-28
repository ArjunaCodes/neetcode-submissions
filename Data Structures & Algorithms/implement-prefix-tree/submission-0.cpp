class PrefixTree {
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
    PrefixTree() {
        root = new trie();
    }
    
    void insert(string word) {
        trie* curr = root;
        for(auto ch: word) {
            if(not curr->childs[ch - 'a']){
                curr->childs[ch - 'a'] = new trie();
            }
            curr = curr->childs[ch - 'a'];
        }
        curr->is_end_of_word = true;
    }
    
    bool search(string word) {
        trie* curr = root;
        for(auto ch: word) {
            int index = ch - 'a';
            if(not curr->childs[index]) {
                return false;
            }
            curr = curr->childs[index];
        }
        return curr->is_end_of_word;
    }
    
    bool startsWith(string prefix) {
        trie* curr = root;
        for(auto ch: prefix) {
            int index = ch - 'a';
            if(not curr->childs[index]) {
                return false;
            }
            curr = curr->childs[index];
        }
        return true;
    }
};
