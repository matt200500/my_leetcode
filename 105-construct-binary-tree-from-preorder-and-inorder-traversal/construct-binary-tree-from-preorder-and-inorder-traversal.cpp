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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()){
            return nullptr;
        }

        for (int i = 0; i < inorder.size(); ++i){
            indexes[inorder[i]] = i;
        }
        return DFS(preorder,0, preorder.size() - 1);
    }

private:
    std::unordered_map<int,int> indexes;
    int tree_index = 0;
    TreeNode* DFS(vector<int>& preorder, int l, int r){
        if (l > r){
            return nullptr;
        }
        int root_value = preorder[tree_index];
        ++tree_index;
        TreeNode* root = new TreeNode(root_value);
        int index = indexes[root_value];
        root->left = DFS(preorder, l, index - 1);
        root->right = DFS(preorder, index + 1, r);
        return root;
    }
};
