#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=4, temp=0;
    long long int arr[20];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[i+1]){
            temp++;
        }
    }
    cout<<n-temp<<endl;
    return 0;
}