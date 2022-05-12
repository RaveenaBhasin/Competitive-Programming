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
    int rangeSumBST(TreeNode* root, int low, int high) {
        stack<TreeNode*>st;
        st.push(root);
        int sum = 0;
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            if(curr->val >= low && curr->val <= high){
                sum += curr->val;
            }
            if(curr->val > low){
                if(curr->left){
                    st.push(curr->left);
                }
            }
            if(curr->val < high){
                if(curr->right){
                    st.push(curr->right);
                }
           }
        }
        return sum;
    }
};

