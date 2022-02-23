/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*>mp;
        if(node == NULL){
            return NULL;
        }
        //Copy of first node
        Node* first = new Node(node->val, {});
        mp[node] = first;
        queue<Node*>q;
        q.push(node);
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(auto it : curr->neighbors) {
                //If node is not present in map then create a copy and oush it into queue
                if(mp.find(it) == mp.end()){
                     mp[it] = new Node(it -> val, {}); 
                     q.push(it);
                }
                
                mp[curr]->neighbors.push_back(mp[it]);
                
            }
        }
        return mp[node];
    }
};

