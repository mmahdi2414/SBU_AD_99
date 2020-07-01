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
#define fore(i, l, r) for(auto i = l; i <= r; i++)
#define forn(i, l, r) for(auto i = l; i >= r; i--)
#define REP(i, n) for (int i = 1; i <= n; i++)
#define cinx int x; cin>>x
#define cinxl ll x; cin>>x
#define sout cout<<"\n"
#define ret(x) return cout<<x<<endl , 0;
#define endl "\n"

const ll inf = 1e18;
const int maxn = 1e5 + 5;
const int maxm = 1e4 + 5;
const ll mod = 998244353;

struct Node
{
    int i;
    int d;
    int g;
};
bool operator<(Node a , Node b){
    return a.g > b.g;
}
int d[maxn];
int g[maxn];
int parent[maxn];
int jobs[maxn];
vector<Node> nodes;
int n , k;
int find(int a){
    if (parent[a] == a)
        return a;
    return parent[a] = find(parent[a]);
}

void merge (int a, int b){
    parent[a] = b;
}

int main(){
    cin>>n;
    int mxd = 0;
    fore(i ,1 , n){
        cin>>d[i]>>g[i];
        nodes.pub({i , d[i] , g[i]});
        mxd = max(mxd , d[i]);
    }
    k = min(n , mxd);
    fore(i , 0, k){
        parent[i] = i;
        jobs[i] = 0;
    }
    sort(all(nodes));
    ll ans = 0;
    for(auto node : nodes){
        int a = find(min(k , node.d));
        if (a == 0)
            continue;
        jobs[a] = node.i;
        ans += node.g;
        int b = find(a - 1);
        merge(a , b);
    }
    cout<<ans<<endl;
    fore(i ,0 , k){
        if (jobs[i] == 0)
            continue;
        cout<<jobs[i]<< " ";
    }
    sout;

}