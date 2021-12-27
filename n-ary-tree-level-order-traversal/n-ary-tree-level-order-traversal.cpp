/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>v;
        if(root == NULL){
            return {};
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            while(size--){
                Node* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                for(auto it:curr->children){
                    q.push(it);
                }
            }
            v.push_back(level);
        }
        return v;
    }
};