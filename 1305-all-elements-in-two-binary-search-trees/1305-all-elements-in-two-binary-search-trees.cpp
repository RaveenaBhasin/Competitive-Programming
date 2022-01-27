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
    void inorder(TreeNode* root, vector<int>&res){
        if(root == NULL){
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>a1, a2;
        inorder(root1, a1);
        inorder(root2, a2);
        vector<int>ans;
        int i = 0, j = 0;
        while(i < a1.size() && j < a2.size()){
            if(a1[i] < a2[j]){
                ans.push_back(a1[i++]);
            }
            else{
                ans.push_back(a2[j++]);
            }
        }
        while(i < a1.size()){
            ans.push_back(a1[i++]);
        }
        while(j < a2.size()){
            ans.push_back(a2[j++]);
        }
        return ans;
        
    }
};

