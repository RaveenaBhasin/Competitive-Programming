#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int count = 0;
    for(int a=0;a*a<=n && a<=m; a++){
        int b = n - a*a;
        if(a+b*b == m){
            count++;                
        }
    }
    cout<<count<<endl;
    return 0;
}