#include<bits/stdc++.h>
using namespace std;

/*---------------------------------------------------------*/
#define int long long int 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define tc int t; cin>>t; while(t--)
#define MOD 1000000007
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define ff first
#define sc second
#define sort(v) sort(v.begin(), v.end());
#define gsort(v) sort(v.begin(), v.end(), greater<int>())
#define mn(v) *min_element(v.begin(), v.end())
#define mx(v) *max_element(v.begin(), v.end())
#define ar(arr, n) int arr[n]; fr(i, 0, n) cin>>arr[i]
#define av(v, n) vector<int>v(n); fr(i, 0, n) cin>>v[i]
#define fmax(a, b) (a = max((a), (b)))
#define fmin(a, b) (a = min((a), (b)))
#define lcm(a, b) (a/__gcd(a, b)*b
#define mii map<int, int>
#define pii pair<int, int>
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
/*---------------------------------------------------------*/

void help(){
	int a, b, c;
    cin>>a>>b>>c;
    int x = 0, y = 0, z = 0;
    if(a <= max(b,c))
    {
        x = max(b,c) + 1 - a;
    }
    if(b <= max(a,c))
        {
            y = max(a,c) + 1 - b;
        }
    if(c <= max(a,b))
        {
            z = max(b,a) + 1 - c;
        }
    cout << x << " " << y << " " << z << endl;
}

int32_t main(){
	fastio;
	tc{
		help();
	}
	return 0;
}