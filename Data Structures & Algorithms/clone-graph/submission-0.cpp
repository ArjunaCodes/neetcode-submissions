/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(not node) return node;
        unordered_map<Node*, Node*> visited;
        queue<Node*> que;
        que.push(node);
        queue<Node*> copy_que;
        Node* new_copy = new Node(node->val);
        copy_que.push(new_copy);
        visited.insert({node, new_copy});
        while(not que.empty()) {
            Node* temp = que.front();
            que.pop();
            Node* copy = copy_que.front();
            copy_que.pop();
            for(auto neighbor: temp->neighbors) {
                if(visited.find(neighbor) == visited.end()) {
                    Node* neighbor_copy = new Node(neighbor->val);
                    copy->neighbors.push_back(neighbor_copy);
                    que.push(neighbor);
                    copy_que.push(neighbor_copy);
                    visited.insert({neighbor, neighbor_copy});
                } else
                {
                    copy->neighbors.push_back(visited[neighbor]);
                }
            }
        }
        return new_copy;
    }
};
