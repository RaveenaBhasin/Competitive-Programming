#include<bits/stdc++.h>
using namespace std;

/*---------------------------------------------------------------*/
#define int long long int
#define fl(i, a, b) for(int i = a; i<b; i++)
#define vi vector<int>
#define PB push_back
#define mp make_pair
#define tc int t; cin>>t; while(t--)
#define aa(arr,n) int arr[n]; fl(i,0,n) cin>>arr[i];
#define av(arr, n) vector<int> arr(n); fl(i,0,n) cin>>arr[i];
#define vvi vector<vector<int>>
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define mii map<int,int>
#define R return
#define B break
#define ff first
#define ss second
#define rmin(a,b) (a=min((a), (b)))
#define rmax(a,b) (a=max((a), (b)))
#define C continue
#define lcm(a,b) (a/__gcd(a, b))*b
#define mod 1000000007
/*--------------------------------------------------------------*/

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    fl(i, 0, n){
        cin>>v[i];
    }
    int sum=0;
    while(!is_sorted(v.begin(), v.end())){
        for(int i=sum%2;i+1<n;i+=2){
            if(v[i]>v[i+1]){
                swap(v[i], v[i+1]);
            }        
        }
        sum++;
    }
    cout<<sum<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tc{
        solve();
    }
    return 0;
}
