#include <bits/stdc++.h>
// #include <chrono> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 
// using namespace std::chrono;


#define ordered_set tree<ii, null_type,less<ii>, rb_tree_tag,tree_order_statistics_node_update> 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ii pair<int, int>
#define LOG(x) cout << x <<" ";
#define TRACE(x) cout << #x << " : " << x << endl
#define LOG2DArray(array, n, m) for ( int i = 1; i <= n ; i++) { for (int j = 1; j <= m; j++) { LOG(array[i][j]); } cout<<endl; } cout<<endl;
#define LOG1DArray(array, n)  for( int i = 0; i < n ; i++){ cout<<i << " : ";LOG( array[i]); } cout<<endl;
#define myFor(i, l, r) for(int i = (int) l;i< (int) r;i++)
#define _ << " : " <<
#define L(a) (int)((a).size())
#define sqr(x) ((x) * 1ll * (x))
#define vi vector<int>
#define vl vector<ll>
#define pub push_back
#define pob pop_back
#define vii vector <ii>
#define vs vector <string>
#define all(s) (s).begin(),(s).end()
#define allb(s,b) (s).begin()+b,(s).end()
#define allr(s) (s).rbegin(),(s).rend()
#define fore(i, l, r) for(ll i = (ll)l; i <= (ll)r; i++)
#define forn(i, l, r) for(int i = (int)l; i >= (int)r; i--)
#define REP(i, n) for (int i = 1; i <= n; i++)
#define cinx int x; cin>>x
#define cinxl ll x; cin>>x
#define sout cout<<"\n"
#define ret(x) return cout<<x<<endl , 0;
#define endl "\n"

const ll inf = 1e18;
const int maxn = 5e2 + 5;
const int maxm = 1e4 + 5;
const ll mod = 998244353;


int n , k;
int arr[maxn];
ll dp[maxn][maxn];
int main(){
    cin>>n;
    fore(i , 1, n + 1){
        cin>>arr[i];
    }
    fore(l , 2 , n){
        fore(i ,1, n - l + 1){
            int j = i + l - 1;
            dp[i][j] = inf;
            fore(k , i , j - 1){
                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k + 1][j] + arr[i] * arr[j + 1] * arr[k + 1]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
}