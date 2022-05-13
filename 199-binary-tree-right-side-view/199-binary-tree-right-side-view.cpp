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
    void dfs(TreeNode* root, vector<int>&res, int height, int& maxHeight){
        if(!root){
            return;
        }
        if(height > maxHeight){
            maxHeight = height;
            res.push_back(root->val);
        }
        dfs(root->right, res, height+1, maxHeight);
        dfs(root->left, res, height+1, maxHeight);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return{};
        }
        int maxHeight = 0;
        vector<int>res;
        res.push_back(root->val);
        dfs(root, res, 0, maxHeight);
        return res;
    }
};