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
    vector<vector<int>>res;
    void dfs(TreeNode* root, int targetSum, vector<int>&path){
        if(!root) return;
        path.push_back(root->val);
        targetSum -= root->val;
        if(root->left == NULL && root->right == NULL){
            if(targetSum == 0){
                res.push_back(path);
            }
        }
        else{
            dfs(root->left, targetSum, path);
            dfs(root->right, targetSum, path);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        dfs(root, targetSum, path);
        return res;
    }
};

