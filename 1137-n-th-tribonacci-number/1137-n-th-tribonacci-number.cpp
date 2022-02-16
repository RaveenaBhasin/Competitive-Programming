class Solution {
public:
    int nthTri(int n, unordered_map<int, int>&mp) { 
        if(n == 0){
            return n;
        }
        if(n == 1 || n == 2){
            return 1;
        }
        int currKey = n;
        if(mp.find(currKey) != mp.end()) {
            return mp[currKey];
        }
        int first = nthTri(n-1, mp);
        int second = nthTri(n-2, mp);
        int third = nthTri(n-3, mp);
        mp[currKey] = first + second + third;
        return first + second + third;
    }
    int tribonacci(int n) {
        unordered_map<int, int>mp;
        return nthTri(n, mp);
    }
};