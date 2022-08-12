class LRUCache {
public:
    class Node{
        public:
        Node *next;
        Node *prev;
        int key;
        int value;
        Node(int _key, int _value) 
        {
            key=_key;
            value=_value;
        }
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*>mp;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    void addnode(Node* newnode)
    {
        Node* temp=head->next;
        newnode->prev=head;
        newnode->next=temp;
        head->next=newnode;
        temp->prev=newnode;
    }
    void deletenode(Node* delnode)
    {
        Node* deletenext=delnode->next;
        Node* deleteprev=delnode->prev;
        deletenext->prev=deleteprev;
        deleteprev->next=deletenext;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            Node* resnode=mp[key];
            int res=resnode->value;
             mp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mp[key]=head->next;
            return res;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node* existingnode=mp[key];
            deletenode(existingnode);
            mp.erase(key);
        }
        else if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
            
        }
        addnode(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */