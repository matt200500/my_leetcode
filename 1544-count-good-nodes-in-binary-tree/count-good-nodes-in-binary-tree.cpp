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
    int goodNodes(TreeNode* root) {
        return DFS(root, root->val);
    }
private:
    int DFS(TreeNode* root, int max_value){
        if (root == nullptr){
            return 0;
        }
        if(max_value <= root->val){
            return 1 + DFS(root->left, root->val) + DFS(root->right, root->val);
        }
        return DFS(root->left, max_value) + DFS(root->right, max_value);
    }
};
