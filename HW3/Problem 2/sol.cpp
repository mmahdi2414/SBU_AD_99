#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define pub push_back
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)


const ll inf = 1e18;
const int maxn = 2e5 + 5;


int n , m , k;
vector<ii> adj[maxn];
bool inqueue[maxn];
ll dis[maxn];

int main(){
	cin>>n>>m>>k;
	fore(i , 1 , n){
		dis[i] = inf;
	}

	fore(i , 1 , m){
		int u , v , w;
		cin>>u>>v>>w;
		adj[u].pub({v , w});
		adj[v].pub({u , w});
	}
	queue<int> q;
	q.push(1);
	dis[1] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		// TRACE(u);
		inqueue[u] = false;

		for(auto it : adj[u]){
			int v = it.first;
			int w = it.second;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				if(!inqueue[v]){
					inqueue[v] = true;
					q.push(v);
				}
			}
		}
	}
	sort(dis + 1 , dis + 1 + n);
	if (dis[k] == inf)
		return cout<<-1<<endl , 0;
	cout<<dis[k]<<endl;

}