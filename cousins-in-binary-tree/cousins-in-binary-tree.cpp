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
    int xdepth, ydepth, xparent, yparent;
    void dfs(TreeNode* root, int x, int y, int depth, int parent){
        if(root == NULL){
            return;
        }
        if(root->val == x){
            xdepth = depth;
            xparent = parent;
        }
        if(root->val == y){
            ydepth = depth;
            yparent = parent;
        }
        dfs(root->left, x, y, depth+1, root->val);
        dfs(root->right, x, y, depth+1, root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y){
            return false;
        }
        dfs(root, x, y, 0, 0);
        if(xdepth == ydepth && xparent!=yparent){
            return true;
        }
        return false;
    }
};