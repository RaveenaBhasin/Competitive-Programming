class Solution {
public:
    string getSmallestString(int n, int k) {
        string s;
        k -= n;
        for(int i = n-1; i >= 0; i--){
            if(k >= 25){
                s.push_back('z');
                k -= 25;
            }
            else{
                s.push_back(k + 'a');
                k = 0;
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
