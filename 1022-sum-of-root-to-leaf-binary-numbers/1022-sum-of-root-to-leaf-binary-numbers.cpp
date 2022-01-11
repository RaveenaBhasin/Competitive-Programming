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
    int solve(TreeNode* root, int n){
        if(root == NULL){
            return 0; 
        }
        n = n*2+root->val;
        
        if(!root->left && !root->right) 
			return n;
        else {
			return solve(root->left,n) + solve(root->right,n); //sum of value at root
		}
           
        
    }
   
    int sumRootToLeaf(TreeNode* root) {
        int ans = solve(root,0);
        return ans;
    }
};