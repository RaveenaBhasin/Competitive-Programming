#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int res = 240-k, sum=0, q=0;
    for(int i=1;i<=n;i++){
        sum += i*5;
        if(sum>res){
            break;
        }
        q++;
    }
    cout<<q<<endl;
}