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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_size = 0;
        int l2_size = 0;
        ListNode* l1_current = l1;
        ListNode* l2_current = l2;
        ListNode* current = new ListNode(0);
        ListNode* first_head = current;
        int carry = 0;
        while(l1_current != nullptr || l2_current != nullptr || carry > 0 ){ // get numbers in both
            int l1_number = 0;
            int l2_number = 0;
            if (l1_current != nullptr){
                l1_number = l1_current->val;
                l1_current = l1_current->next;
            }
            if (l2_current != nullptr){
                l2_number = l2_current->val;
                l2_current = l2_current->next;
            }
            int combined = l1_number + l2_number + carry;
            carry = combined / 10;
            int digit = combined % 10;
            ListNode* added_node = new ListNode(digit);
            current->next = added_node;
            current = current->next;
        }
        return first_head->next;
    }
};
