/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* copy = dummy;
        unordered_map<Node*, Node*> mapper;
        Node* temp = head;
        while(head) {
            copy->next = new Node(head->val);
            copy = copy->next;
            mapper[head] = copy;
            head = head->next;
        }
        copy = dummy->next;
        while(temp) {
            copy->random = mapper[temp->random];
            copy = copy->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};
