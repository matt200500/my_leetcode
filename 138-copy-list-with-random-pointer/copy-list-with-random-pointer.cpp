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
        if(head == nullptr){
            return head;
        }
        Node* current_head = new Node(head->val);
        Node* start_head = current_head;
        Node* original_head = head;
        std::unordered_map<Node*,Node*> nodes;
        nodes[original_head] = current_head;

        while (original_head->next != nullptr){
            original_head = original_head->next;
            current_head->next = new Node(original_head->val);
            current_head = current_head->next;
            nodes[original_head] = current_head;
        }

        original_head = head;
        current_head = start_head;
        while(original_head != nullptr){
            current_head->random = nodes[original_head->random];
            original_head = original_head->next;
            current_head = current_head->next;
        }

        return start_head;
    }

};
