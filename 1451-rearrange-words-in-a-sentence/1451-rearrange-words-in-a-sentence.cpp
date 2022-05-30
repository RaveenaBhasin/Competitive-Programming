class Solution {
    static bool cmp(pair<string, int>&a, pair<string, int>&b){
        if(a.first.size() == b.first.size()){
            return a.second < b.second;
        }
        return a.first.size() < b.first.size();
    }
public:
    string arrangeWords(string text) {
        vector<pair<string, int>>v;
        string temp;
        text[0] = tolower(text[0]);
        text += ' ';
        for(int i = 0; i < text.size(); i++){
            if(text[i] == ' '){
                v.push_back({temp, i});
                temp = "";
            }
            else{
                temp += text[i];
            }
        }
        sort(v.begin(), v.end(), cmp);
        temp = "";
        for(auto ch : v){
            temp += ch.first;
            temp += ' ';
        }
        temp[0] = toupper(temp[0]);
        return temp.substr(0, temp.size()-1);
    }
};