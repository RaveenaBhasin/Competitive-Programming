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
    queue<TreeNode*>ele;
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        ele.push(root);
        inorder(root->right);  
    }
    void arrange(TreeNode* root){
        if(ele.empty()){
            return;
        }
        root->right = ele.front();
        root->left = root->right->left = root->right->right = NULL;
        ele.pop();
        arrange(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        root = new TreeNode();
        arrange(root);
        return root->right;
    }
};
