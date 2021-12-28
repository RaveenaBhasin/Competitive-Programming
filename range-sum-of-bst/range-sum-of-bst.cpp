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
private:
    int sum=0;
public:
    void dfs(TreeNode* root, int low, int high){
        if(!root){
            return;
        }
        if(root->val>=low && root->val<=high){
            sum+=root->val;
        }
        if(root->val>low){
            dfs(root->left, low, high);
        }
        if(root->val<high){
            dfs(root->right, low, high);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);
        return sum;
    }
};

//T.C : O(n)  S.C : O(n)   n = number of nodes

