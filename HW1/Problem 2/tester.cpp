#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define ii pair<int, int>
#define LOG(x) cerr << x <<" ";
#define TRACE(x) //cout << #x << " : " << x << endl
#define LOG2DArray(array, n, m) for ( int i = 0; i < n ; i++) { for (int j = 0; j < m; j++) { LOG(array[i][j]); } cout<<endl; } cout<<endl;
#define LOG1DArray(array, n)  for( int i = 0; i < n ; i++){ LOG( array[i]); } cout<<endl<<endl;
#define myFor(i, l, r) for(int i = (int) l;i< (int) r;i++)
#define _ << ":" <<
#define L(a) (int)((a).size())
#define sqr(x) ((x) * 1ll * (x))
#define vi vector<int>
// #define mp make_pair
#define pub push_back
#define pob pop_back
#define vii vector <ii>
#define vs vector <string>
#define all(s) (s).begin(),(s).end()
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)
#define REP(i, n) for (int i = 1; i <= n; i++)
const int maxn = 2e5 + 5;
const int inf = 1e9;


vi adj[maxn];
int n;
int parent[maxn];
int arr[20];
ii get(int u , int v){
	return {min(u , v) , max(u , v)};
}
map<ii , bool> visited;
void dfs(int u , int par){
	parent[u] = par;
	for(auto v : adj[u])
	{
		if (v != par)
			dfs(v , u);
	}
}

void solve(int s, int t){
	vi path;
	while (t != -1){
		path.pub(t);
		t = parent[t];
	}
	fore(i , 1 , path.size() - 1){
		visited[get(path[i] , path[i - 1])] = true;
	}
}
int main(int argc, char const *argv[])
{
	TRACE("start");
	ifstream test_in(argv[1]);    /* This stream reads from test's input file   */
	ifstream test_out(argv[2]);   /* This stream reads from test's output file  */
	ifstream user_out(argv[3]);   /* This stream reads from user's output file  */	
	test_in>>n;
	TRACE(n);
	fore(i , 2, n){
		int u , v;
		test_in>>u>>v;
		adj[u].pub(v);
		adj[v].pub(u);
	}

	int my , him , a , b , c;
	string s;
	getline(test_out , s);
	my = stoi(s);
	TRACE(my);
	int cnt = 0;
	while (getline(user_out , s) && cnt < 10)
	{
		for(char c : s)
			if (!(c >='0' && c<='9'))
				return 1;
		TRACE(s);
		arr[cnt++] = stoi(s);
	}
	TRACE(cnt);
	if (!(cnt == 5 || cnt == 4))
		return 1;
	him = arr[0];
	if (him != my)
		return 1;

	fore(i ,1 , 3){
		dfs(arr[i] , -1);
		TRACE(i);
		fore(j , i + 1 , 3){
			solve(arr[i] , arr[j]);
			TRACE(j);
		}
	}
	TRACE("check");
	visited.size();
	if (visited.size() != him)
		return 1;
	TRACE("ok");
	return 0;
}