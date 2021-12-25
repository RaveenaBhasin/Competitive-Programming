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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){   //Empty tree
            return true;
        }
        return symmetricTest(root->left, root->right);
    }
    bool symmetricTest(TreeNode* a, TreeNode* b){
        if(a == NULL && b == NULL){   //Both are NULL
            return true;
        }
        else if(a == NULL || b == NULL){   //one of them is NULL
            return false;
        }
        else if(a->val != b->val){
            return false;
        }
        return symmetricTest(a->left, b->right) && symmetricTest(a->right, b->left);
    }
};

