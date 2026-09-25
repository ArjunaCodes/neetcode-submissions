class MyHashSet {
    struct LList{
        int value;
        LList* next;
    };
    std::vector<LList*> hash_table{77777, nullptr};
    int hash {7};
public:
    MyHashSet() {
        
    }
    int get_hash_key(int key) {
        return (key % 77777);
    }
    
    void add(int key) {
        if(contains(key)) return;
        int location {get_hash_key(key)};
        if(hash_table[location] == nullptr) {
            hash_table[location] = new LList{key, nullptr};
        }
        else {
            LList* node = hash_table[location];
            while(node->next){
                node = node->next;
            }
            node -> next = new LList{key, nullptr};
        }
    }
    
    void remove(int key) {
        int location{get_hash_key(key)};
        if(hash_table[location] != nullptr) {
            LList* prev = hash_table[location];
            if(not prev) return;
            if(prev->value == key) {
                hash_table[location] = prev->next;
                std::cout<< "removed " << prev->value << std::endl;
                delete prev;
                return;
            }
            LList* curr = prev->next;
            while(curr and curr->value != key){
                prev = curr;
                curr = curr->next;
            }
            if(curr and curr->value == key) {
                prev->next = curr->next;
                std::cout<< " removed " << curr->value << std::endl;
                delete (curr);
            }
        }
    }
    
    bool contains(int key) {
        int location{get_hash_key(key)};
        LList* node = hash_table[location];
        while(node and node->value != key) {
            node = node->next;
        }
        return node && node->value == key;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */