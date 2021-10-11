#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    unordered_map<int,int>m;
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
    }
    if(m.size()%2==0){
        cout<<"CHAT WITH HER!"<<endl;
    }
    else if(m.size()%2!=0){
        cout<<"IGNORE HIM!"<<endl;
    }
    return 0;
}