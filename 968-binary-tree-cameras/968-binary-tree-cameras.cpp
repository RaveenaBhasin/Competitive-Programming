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

    int count = 0;
    int helper(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return -1;
        
        int left = helper(root->left);
        int right = helper(root->right);
        
        if(root->val == INT_MAX && left == -1){
            ++count;
            return 1;
        }
        
        if(left == -1 || right == -1){
            ++count;
            return 1;
        } 
        else if(left == 1 || right == 1){
            return 0;
        } 
        else {
            return -1;
        }
        
    }
    
    int minCameraCover(TreeNode* root) {
        TreeNode* dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        helper(dummy);
        return count;
    }
};