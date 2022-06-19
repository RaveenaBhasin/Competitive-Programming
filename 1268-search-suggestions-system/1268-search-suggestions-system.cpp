class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string, vector<string>>mp;
        sort(products.begin(), products.end());
        for(auto it : products){
            string temp = "";
            for(int i = 0; i < it.size(); i++){
                temp += it[i];
                if(mp[temp].size() < 3){
                    mp[temp].push_back(it);
                }
            }
        }
        vector<vector<string>>res;
        string subStr = "";
        for(int i = 0; i < searchWord.size(); i++){
            subStr += searchWord[i];
            res.push_back(mp[subStr]);
        }
        return res;
    }
};
