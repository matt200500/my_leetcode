/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){ // get the middle of list
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the list after slow (second half)
        ListNode* current = slow->next;
        slow->next = nullptr;
        ListNode* previous = nullptr;
        while(current != nullptr){
            ListNode* temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }
    
        ListNode* first_half = head;
        ListNode* second_half = previous;
        while(second_half != nullptr){
            ListNode* temp1 = first_half->next;
            ListNode* temp2 = second_half->next;

            first_half->next = second_half;
            second_half->next = temp1;

            first_half = temp1;
            second_half = temp2;
        
        }
    }
};
