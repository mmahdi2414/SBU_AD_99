#include <bits/stdc++.h>

using namespace std;

#define fore(i , l , r) for(auto i = l ; i <= r ; i++)


const int MAXN = 1e5 + 5;
const int INF = 1e9;

int n , s;
vector<int> adj[MAXN];
int dis[MAXN];

int main(){
	cin>>n>>s;
	fore(i ,1 , s){
		int u , v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fore(i , 1, n){
		dis[i] = INF;
	}
	int h , t;
	cin>>h>>t;

	dis[t] = 0;
	queue<int> q;
	q.push(t);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v : adj[u]){
			if (dis[u] + 1 < dis[v]){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}

	int m;
	cin>>m;

	fore(i , 1, m){
		int u;
		cin>>u;
		if (dis[u] <= dis[h])
			return cout<<"NO"<<endl , 0;
	}
	cout<<"YES"<<endl;

}

