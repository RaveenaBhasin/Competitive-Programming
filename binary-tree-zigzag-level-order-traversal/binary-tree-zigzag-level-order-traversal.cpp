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
    //Reverse the alternate levels in level order traversal
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        queue<TreeNode*>q;
        if(root == NULL){
            return v;
        }
        q.push(root);
        int count = 1;
        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            while(size--){
                TreeNode* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            if(count%2==0){
                reverse(level.begin(), level.end());
            }
            v.push_back(level);
            count++;
        }
        return v;
    }
};