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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;

        if (root == nullptr){
            return output;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> current_row;
            vector<TreeNode*> next_level;
            while(!q.empty()){
                TreeNode* current = q.front();
                q.pop();
                current_row.push_back(current->val);
                if (current->left != nullptr){
                    next_level.push_back(current->left);
                }
                if (current->right != nullptr){
                    next_level.push_back(current->right);
                }
            }
            output.push_back(current_row);
            for (int i = 0 ; i < next_level.size(); ++i){
                q.push(next_level[i]);
            }
            
        }
        return output;
    }
};
