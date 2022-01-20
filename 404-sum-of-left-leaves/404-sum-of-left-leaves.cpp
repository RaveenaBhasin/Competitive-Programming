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
    int res = 0;
    void dfs(TreeNode* root, int dir) {
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL){
            if(dir == 1){
                res += root->val;
                return;
            }
        }
        dfs(root->left, 1);
        dfs(root->right, 0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root, -1);
        return res;
    }
};



