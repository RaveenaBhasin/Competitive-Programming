// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int>ans;
        unordered_map<int, int>mp;
        int uniqueEle = 0;
        for(int i = 0; i < k-1; i++){
            int currentVal = A[i];
            if(mp.find(currentVal) != mp.end()){
                mp[currentVal] += 1;
            }
            else{
                mp[currentVal] = 1;
                uniqueEle += 1;
            }
        }
        int release = 0;
        for(int acquire = k-1; acquire < n; acquire++){
            int currentVal = A[acquire];
            if(mp.find(currentVal) != mp.end()){
                mp[currentVal] += 1;
            }
            else{
                mp[currentVal] = 1;
                uniqueEle += 1;
            }
            ans.push_back(uniqueEle);
            int discard_val = A[release];
            mp[discard_val] -= 1;
            if(mp[discard_val] == 0){
                mp.erase(discard_val);
                uniqueEle -= 1;
            }
            release += 1;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends