#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        unordered_map<int,int>m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        int p=0, q=0;
        for(auto it:m){
            if(it.second>1){
                p++;
            }
            else if(it.second==1){
                q++;
            }
        }
        cout<<p+q/2<<endl;
    }
    return 0;
}