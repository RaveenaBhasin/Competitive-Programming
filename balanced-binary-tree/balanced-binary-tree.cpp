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
    bool ans = true;
    int height(TreeNode* root) {
        if(!root){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh-rh) > 1){
            ans = false;
        }
        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) {
            return true;
        }
        height(root);
        return ans;
    }
};


