class Trie {
private:
struct TrieNode{
    struct TrieNode *child[26];
    bool end;
};
TrieNode* node;
public:
    Trie() {
        node = new TrieNode();
    }
    void insert(string word) {
        TrieNode* curr = node;
        for(char ch : word){
            if(curr->child[ch - 'a'] == NULL){
                curr->child[ch-'a'] = new TrieNode();
            }
            curr = curr->child[ch-'a'];
        }
        curr->end = true;
    }
    
    bool search(string word){
        TrieNode* curr = node;
        for(char ch : word){
            if(curr->child[ch-'a'] == NULL){
                return false;
            }
            curr = curr->child[ch-'a'];
        }
        return curr->end;
    }
   
    bool startsWith(string prefix) {
        TrieNode* curr = node;
        for(char ch : prefix){
            if(curr->child[ch-'a'] == NULL){
                return false;
            }
            curr = curr->child[ch-'a'];
        }
        return true;
    }
};

