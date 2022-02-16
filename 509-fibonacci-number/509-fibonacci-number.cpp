class Solution {
public:
    int nthFib(int n, unordered_map<int, int>&mp) {
        if(n <= 1){
            return n;
        }
        int currKey = n;
        if(mp.find(currKey) != mp.end()){
            return mp[currKey];
        }
        int first = nthFib(n-1, mp);
        int second = nthFib(n-2, mp);
        mp[currKey] = first + second;
        return first + second;
    }
    int fib(int n) {
        unordered_map<int, int>mp;
        return nthFib(n, mp);
    }
};