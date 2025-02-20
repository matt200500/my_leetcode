/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool is_equal = true;
        DFS(p, q, is_equal);
        return is_equal;
    }

private:
    void DFS(TreeNode* p, TreeNode* q, bool&is_equal){
        
        if(p == nullptr && q == nullptr){
            return;
        }
        if(q == nullptr && p != nullptr){
            is_equal = false;
            return;
        }
        if(q != nullptr && p == nullptr){
            is_equal = false;
            return;
        }
        
        if(p->val != q->val){
            is_equal = false;
        }

        DFS(p->left, q->left, is_equal);
        DFS(p->right, q->right, is_equal);
    }
};
