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
    int maxDepth(TreeNode* root) {
        return depth_first_search(root);
    }

private:
    int depth_first_search(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }

        if (root->left != nullptr && root->right != nullptr){
            return max(depth_first_search(root->left) + 1, depth_first_search(root->right) + 1);
        }
        if(root->right != nullptr){
            return depth_first_search(root->right) + 1;
        } 
        if(root->left != nullptr){
            return depth_first_search(root->left) + 1;
        } 
        return 0;
    }
};
