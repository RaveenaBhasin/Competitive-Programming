#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, c0, c1, h, count=0;
        cin>>n>>c0>>c1>>h;
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                count += min(c0, c1+h);
            }
            else{
                count += min(c1, c0+h);
            }
        }
        cout<<count<<endl;
    }
    return 0;
}