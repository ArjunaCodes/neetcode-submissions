
class MyHashMap {
    struct LList{
        int value;
        int content;
        LList* next;
    };
    unsigned int bucket_size{1};
    std::vector<LList*> hash_table;
    int elements_count{0};
    double load_factor{1};

    void rehash() {
        unsigned int new_bucket_size = bucket_size * 2;
        std::vector<LList*> new_hash_table(new_bucket_size, nullptr);
        for(int i=0; i<bucket_size; ++i) {
            LList* node = hash_table[i];
            while(node) { // recalculate hash and insert it to new hash table.
                LList* node_next = node->next;
                int new_key = std::abs(node->value) % new_bucket_size;
                node->next = new_hash_table[new_key];
                new_hash_table[new_key] = node;
                node = node_next;
            }
        }
        bucket_size = new_bucket_size;
        hash_table  = new_hash_table;
    }

public:
    MyHashMap(): hash_table{bucket_size, nullptr} {
        
    }
    int get_hash_key(int key) {
        return std::abs(key) % bucket_size;
    }
    
    void put(int key, int value) {
        if (elements_count >= (int)bucket_size) {
            rehash();
        }

        int hash_key = get_hash_key(key);
        LList* node  = hash_table[hash_key];
        if(not node) {
            elements_count++;
            hash_table[hash_key] = new LList{key, value, nullptr};
            return;
        }
        while(node) {
            if(node->value == key){
                node->content = value;
                return;
            }
            if(node->next == nullptr){
                node->next = new LList{key, value, nullptr};
                elements_count++;
                break;
            }
            node = node->next;
        }
    }
    
    void remove(int key) {
        int hash_key = get_hash_key(key);
        LList* node  = hash_table[hash_key];
        LList* prev  = nullptr;
        while(node) {
            if(node->value == key) {
                if (!prev) {
                    hash_table[hash_key] = node->next; // Removing the head node
                } else {
                    prev->next = node->next; // Removing middle/tail node
                }
                delete node;
                elements_count--;
                return;
            }
            prev = node;
            node = node->next;
        }
    }
    
    int get(int key) {
        LList* node = hash_table[get_hash_key(key)];
        while(node) {
            if(node->value == key) return node->content;
            node = node->next;
        }
        return -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */