class LinkedList {
    struct Node{
        int data;
        Node* next;
    };
    Node* Head;
    int   size;
public:
    LinkedList():Head{nullptr}, size{-1} {

    }

    int get(int index) {
        Node* temp = Head;
        while(index-- and temp) {
            temp = temp->next;
        }
        if(temp) return temp->data;
        return -1;
    }

    void insertHead(int val) {
        Node* temp = new Node{val, nullptr};
        if(Head) {
            temp->next = Head;
        }
        Head = temp;
    }
    
    void insertTail(int val) {
        Node* temp =  new Node{val, nullptr};
        if(not Head) {
            insertHead(val);
            return;
        }
        Node* itr  = Head;
        while(itr->next) {
            itr = itr->next;
        }
        itr->next = temp;
    }

    bool remove(int index) {
        Node* itr = Head;
        if(index == 0 and not Head) return false;
        if(index == 0) {
            Head = Head->next;
            delete itr;
            return true;
        }
        while(--index and itr) {
            itr = itr->next;
        }
        if(itr and itr->next) {
            Node* del_node = itr->next;
            itr->next = del_node->next;
            delete del_node;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        Node* itr = Head;
        std::vector<int> values;
        while(itr) {
            values.emplace_back(itr->data);
            itr = itr->next;
        }
        return values;
    }
};
