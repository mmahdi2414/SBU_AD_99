#include <bits/stdc++.h>

using namespace std;

#define fore(i , l , r) for(auto i = l ; i <= r ; i++)
#define ii pair<int, int> 

const int MAXN = 2e5 + 5;


int n;
vector<int> adj[MAXN];
vector<int> diameter;
int parent[MAXN];
int mxlvl = 0;
int c;
map<ii , bool> visited;

inline ii get(int u, int v){
	return {min(u , v),  max(u , v)};
}

int bfs(int s){
	queue<int> q;
	q.push(s);
	int a = s;
	parent[s] = s;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		a = u;
		for(auto v : adj[u]){
			if (v != parent[u]){
				parent[v] = u;
				q.push(v);
			}
		}
	}
	return a;
}
void dfs(int u , int p , int lvl){
	if (lvl > mxlvl)
	{
		c = u;
		mxlvl = lvl;
	}
	for(auto v : adj[u]){
		if (v == p)
			continue;
		dfs(v , u , lvl + visited[get(u , v)]);
	}
}

void find(){
	int a = bfs(1);
	int b = bfs(a);

	while(a != b){
		diameter.push_back(b);
		b = parent[b];
	}
	diameter.push_back(a);
}

int main(){
	cin>>n;
	fore(i , 1, n - 1){
		int u , v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		visited[get(u , v)] = true;
	}
	find();
	fore(i , 1, diameter.size() - 1){
		int u = diameter[i - 1];
		int v = diameter[i];
		visited[get(u , v)] = false;
	}
	int a = diameter[0];
	int b = diameter.back();
	dfs(a , a , 0);
	if (mxlvl == 0)
	{
		fore(i , 1 , n){
			if (i != a && b != i)
			{
				c = i;
				break;
			}
		}
	}
	cout<<diameter.size() - 1 + mxlvl<<endl;
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
}