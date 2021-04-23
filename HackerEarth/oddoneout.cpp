#include<iostream>
using namespace std;
#define ll long long int
int main(){
    ios_base::sync_with_stdio(false);    //Fast I/O operations 
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll arr[n-1],sum=0;
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<n*n-sum;
    return 0;
}
