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
    unordered_map<int, int>mp;
    void helper(TreeNode* root) {
        if(root == NULL) return;
        mp[root->val]++;
        helper(root->left);
        helper(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>res;
        helper(root);
        int maxFreq = 0;
        for(auto it: mp) {
            maxFreq = max(maxFreq, it.second);
        }
        for(auto it: mp) {
            if(it.second == maxFreq) {
                res.push_back(it.first);
            }
        }
        return res;
        
    }
};