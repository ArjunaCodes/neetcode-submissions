class LRUCache {
    unsigned int capacity;
    unsigned int size;
    struct Node{
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int key, int value): key(key), value(value), next(nullptr), prev(nullptr) {

        }
    };
    unordered_map<int, Node*> hash_map;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity): capacity(capacity), size(0), head(nullptr), tail(nullptr) {

    }
    
    int get(int key) {
        int value = -1;
        if(hash_map.find(key) != hash_map.end()) {
            hit(hash_map[key]);
            value = hash_map[key]->value;
        }
        return value;
    }

    void hit(Node* hit) {
        // When an update or a get is called on a key, then it is considered as a hit.
        if(hit == head) return;
        if(hit == tail) {
            tail = tail -> prev;
        }
        Node* hit_prev = hit->prev;
        Node* hit_next = hit->next;
        if(hit_prev)
            hit_prev -> next = hit_next;
        if(hit_next) 
            hit_next -> prev = hit_prev;
        
        head->prev = hit;
        hit->next = head;
        hit->prev = nullptr;
        head = hit;
    }
    
    void put(int key, int value) {
        // first key value where head and tail is null.at()
        // key is not present in the hash_map
        // key is present in the hash_map
        // size > capacity; remove the least recently used value;
        if(hash_map.find(key) != hash_map.end()) {
            hit(hash_map[key]);
            hash_map[key]->value = value;
        }
        else {
            Node* new_node = new Node(key, value);
            hash_map[key] = new_node;
            if(head) 
                head->prev = new_node;
            new_node->next = head;
            if(not tail) {
                tail = new_node;
            }
            head = new_node;
            ++size;
        }
        if(size > capacity) {
            Node* rm = tail;
            Node* prev = rm->prev;
            if(prev) {
                prev->next = nullptr;
                tail = prev;
            }
            else {
                tail = nullptr;
                head = nullptr;
            }
            hash_map.erase(rm->key);
            delete rm;
            --size;
        }
    }
};
