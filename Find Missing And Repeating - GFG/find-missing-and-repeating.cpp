// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *res = new int[2];
        unordered_map<int, int>mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        for(int i = 1; i <= n; i++) {
            if(mp[i] == 0){
                res[1] = i;
            }
            if(mp[i] == 2){
                res[0] = i;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends