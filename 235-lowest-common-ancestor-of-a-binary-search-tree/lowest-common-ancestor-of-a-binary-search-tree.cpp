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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int lowest_height = INT_MAX;
        TreeNode* lca = nullptr;
        lowest_ancestor_helper(root, p, q, lowest_height, lca);
        return lca;
    }

private:
    void lowest_ancestor_helper (TreeNode* root, TreeNode* p, TreeNode* q, int& lowest_height, TreeNode*& lca){
        if (root == nullptr) return;
        if (DFS_P(root, p) && DFS_Q(root, q)){ // both are in tree root
            int height = DFS(root);
            if (height < lowest_height){
                lowest_height = height;
                lca = root;
            }
        }
        lowest_ancestor_helper(root->left, p, q, lowest_height ,lca);
        lowest_ancestor_helper(root->right, p, q, lowest_height,lca);
    }

private:
    bool DFS_P(TreeNode* root, TreeNode* p){
        if (root == nullptr){
            return false;
        }
        if(root->val == p->val){ // if p root q
            return true;
        }  
        return DFS_P(root->left, p) || DFS_P(root->right, p);
    }
    bool DFS_Q(TreeNode* root, TreeNode* q){
        if (root == nullptr){
            return false;
        }
        if(root->val == q->val){ // if p root q
            return true;
        }  
        return DFS_Q(root->left, q) || DFS_Q(root->right, q);
    }

    int DFS(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return 1 + max(DFS(root->left), DFS(root->right));
    }
};
