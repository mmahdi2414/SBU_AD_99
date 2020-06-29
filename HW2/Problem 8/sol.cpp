#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define all(s) (s).begin(),(s).end()
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)

const int MAXN = 1e5 + 5;


int n , m , q;
vector<ii> edges;
vector<ii> deletedEdges;
map<ii , bool> mustDelete;
int parent[MAXN];
vector<int> ans;

int find(int a){
	return a == parent[a] ? a : (parent[a] = find(parent[a]));
}
bool merge(int a , int b){
	a = find(a);
	b = find(b);
	if (a==b)
		return false;
	parent[a] = b;
	return true;
}
ii get(int u , int v){
	return {min(u , v) , max(u , v)};
}
int main(){
	cin>>n>>m;
	int moallefe = n;
	fore(i ,1 , n){
		parent[i] = i;
	}
	fore(i , 1 , m){
		int u ,v;
		cin>>u>>v;
		edges.push_back(get(u , v));
	}
	cin>>q;
	fore(i , 1 , q){
		int u , v;
		cin>>u>>v;
		deletedEdges.push_back(get(u , v));
		mustDelete[get(u , v)] = true;
	}
	reverse(all(deletedEdges));
	deletedEdges.pop_back();
	for(auto it : edges){
		if (mustDelete[it])
			continue;
		moallefe -= merge(it.first , it.second);
	}
	ans.push_back(moallefe);
	for(auto it : deletedEdges){
		moallefe -= merge(it.first , it.second);
		ans.push_back(moallefe);
	}
	reverse(all(ans));
	for(auto it : ans){
		cout<<it<<endl;
	}
}  