class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxLen = 0;
        vector<int> mask(words.size());
        for(int i = 0; i < words.size(); i++) {
            for(auto &c: words[i])
                mask[i] |= 1 << (c - 'a');
            for(int j = 0; j < i; j++) 
                if(!(mask[i] & mask[j]))
                    maxLen = max(maxLen, int(words[i].size() * words[j].size()));
        }
        return maxLen;
    }
};
