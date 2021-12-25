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
    int dfs(TreeNode* root, int currSum) {
        if(!root){
            return 0;
        }
        currSum = currSum*10 + root->val;   //Appending current nodes digit
        if(!root->left && !root->right){    //Leaf node
            return currSum;
        }
        return dfs(root->left, currSum) + dfs(root->right, currSum);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
/*T.C : O(N)   N : number of nodes
  S.C : O(H)   H : height of tree*/