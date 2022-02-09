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
    void traversal(TreeNode* root, vector<int>&v) {
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            v.push_back(root->val);
        }
        if(root->left != NULL){
            traversal(root->left, v);
        }
        if(root->right != NULL){
           traversal(root->right, v);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1, v2;
        traversal(root1, v1);
        traversal(root2, v2);
        return v1 == v2;
    }
};