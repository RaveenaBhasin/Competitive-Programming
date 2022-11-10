class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for(auto ch : s){
            if(res.size() && res.back() == ch) {
                res.pop_back();
            }
            else{
                res.push_back(ch);
            }
        }
        return res;
    }
};
