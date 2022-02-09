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
    bool isSame(TreeNode* root, int val){
        if(root == NULL){
            return true;
        }
        if(root->val != val){
            return false;
        }
        bool lefth = isSame(root->left, val);
        bool righth = isSame(root->right, val);
        return lefth && righth;
    }
    bool isUnivalTree(TreeNode* root) {
        return isSame(root, root->val);
    }
};