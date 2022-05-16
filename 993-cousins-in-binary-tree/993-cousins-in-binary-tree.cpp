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
    int xlevel, ylevel, xparent, yparent;
    void dfs(TreeNode* root, int x, int y, int level, int parent){
        if(root == NULL){
            return;
        }
        if(root->val == x){
            xlevel = level;
            xparent = parent;
        }
        if(root->val == y){
            ylevel = level;
            yparent = parent;
        }
        dfs(root->left, x, y, level+1, root->val);
        dfs(root->right, x, y, level+1, root->val);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y){
            return false;
        }
        dfs(root, x, y, 0, 0);
        if(xlevel == ylevel && xparent != yparent){
            return true;
        }
        return false;
    }
};