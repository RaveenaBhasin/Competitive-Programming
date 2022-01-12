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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        TreeNode *temp =root;
        while(temp->left||temp->right)
        {
            if(val<temp->val && temp->left)
                temp = temp->left;
            else if(val>temp->val && temp->right)
                temp = temp->right;
            else{
                break;
            }
        }
        if(val>temp->val)
            temp->right = new TreeNode(val);
        else
            temp->left = new TreeNode(val);
        return root;
    }
};