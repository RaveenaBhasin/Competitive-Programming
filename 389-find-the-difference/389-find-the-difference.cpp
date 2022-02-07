class Solution {
public:
    char findTheDifference(string s, string t) {
        int a = 0, b = 0;
        for(char it : s){
            a += it;
        }
        for(char it : t){
            b += it;
        }
        return b-a;
    }
};