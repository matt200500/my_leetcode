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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool contains_subroot = false;
        ApplyDFS(root, subRoot, contains_subroot);
        return contains_subroot;
    }

private:
    void ApplyDFS(TreeNode* root, TreeNode* subRoot, bool&contains_subroot){
        if (root == nullptr){
            return;
        }
        bool result = DFS(root, subRoot, contains_subroot);
        if (result){
            contains_subroot = true;
        }
        ApplyDFS(root->left, subRoot, contains_subroot);
        ApplyDFS(root->right, subRoot, contains_subroot);
    }

    bool DFS(TreeNode* p, TreeNode* q, bool& contains_subroot){
        if(p == nullptr && q == nullptr){
            return true;
        }
        if(q == nullptr && p != nullptr){
            return false;
        }
        if(q != nullptr && p == nullptr){
            return false;
        }
        
        if(p->val != q->val){
            return false;
        }

        if (DFS(p->left, q->left, contains_subroot) == true && DFS(p->right, q->right, contains_subroot) == true){
            return true;
        }
        return false;
    }
};
