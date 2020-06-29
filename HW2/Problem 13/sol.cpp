#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define all(s) (s).begin(),(s).end()
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)
#define ii pair<int,int>

const int MAXN = 1e3 + 5;

int n , m , p , q;
int parent[MAXN];
vector<int> child [MAXN][3];
vector<pair<ld , ii>> edges;

int find(int x){
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}
bool merge(int u  , int v){
	u = find(u);
	v = find(v);
	if (u == v)
		return false;
	parent[u] = v;
	return true;
}
ld mst(){
	sort(all(edges));
	ld res = 0;
	for(auto it : edges){
		int u = it.second.first;
		int v = it.second.second;
		ld w = it.first;
		if (merge(u ,v)){
			res+=w;
		}
	}
	return res;
}
int main(){
	cin>>n;
	fore(i ,1 ,n){
		parent[i] = i;
		cin>>p>>q;
		fore(k , 1 , p){
			ld x;
			cin>>x;
			child[i][1].push_back(x);
		}
		fore(k , 1 , q){
			ld x;
			cin>>x;
			child[i][2].push_back(x);
		}
		if (p)
			child[i][1][0] = *max_element(all(child[i][1]));
		if (q)
			child[i][2][0] = *max_element(all(child[i][2]));

	
	}
	cin>>m;
	fore(i , 1, m){
		int u , v;
		cin>>u>>v;
		merge(u , v);
	}
	fore(i , 1 , n){
		fore(j , i + 1 , n){
			fore(k , 1,  2){
				if (child[i][k].empty() || child[j][3 - k].empty())
					continue;
				ld a = child[i][k][0];
				ld b = child[j][3 - k][0];
				edges.push_back({1.0 / a + 1.0 / b, {i , j}});
			}
		}
	}
	ld ans = mst();

	cout<<setprecision(10)<<fixed<<ans<<endl;
}