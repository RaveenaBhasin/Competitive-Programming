// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int, int>mp;
        int prefixSum = 0, ans = 0;
        mp[prefixSum] = -1;
        for(int i = 0; i < n; i++){
            int currentVal = A[i];
            prefixSum += currentVal;
            if(mp.find(prefixSum) != mp.end()){
                int temp = i - mp[prefixSum];
                ans = max(temp, ans);
            }
            else{
                mp[prefixSum] = i;
            }
        } 
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends