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
        if(node == nullptr){
            return {};
        }        
        unordered_map<Node*, Node*> checked;
        return DFS(node, checked);
    }

private:
    Node* DFS(Node* node, unordered_map<Node*, Node*>& checked){
        Node* current = new Node(node->val);
        std::vector<Node*> current_neigbors;

        if (checked.find(node) != checked.end()){
            return checked[node];
        }
        checked[node] = current;

        for (int i = 0; i < node->neighbors.size(); ++i){
            current_neigbors.push_back(DFS(node->neighbors[i], checked));
        }
        current->neighbors = current_neigbors;
        return current;
    }
};
