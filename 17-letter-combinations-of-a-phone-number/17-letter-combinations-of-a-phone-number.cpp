class Solution {
public:
    void generateCombinations(string digits, int currIndex ,string currStr, vector<string>&res, unordered_map<char,string>&mp)
    {
        if(currIndex >= digits.size()){
            res.push_back(currStr);
        }
        char currChar = digits[currIndex];
        string mapping = mp[currChar];
        for(int i = 0; i < mapping.size(); i++){
            generateCombinations(digits, currIndex+1, currStr + mapping[i], res, mp);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string>mp{
            {'1',""},
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"},
        };
        vector<string>res;
        if(digits.size() == 0){
            return res;
        }
        generateCombinations(digits, 0, "", res, mp);
        return res;
    }
};