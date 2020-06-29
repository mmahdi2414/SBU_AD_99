#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)


const int MAXN = 300+ 5;
const ll INF = 1e17;

ll dp[MAXN][MAXN];
int path[MAXN][MAXN];
int n , m;

int main(){
	cin>>n>>m;
	fore(i , 1 , n){
		fore(j ,1 , n){
			dp[i][j] = INF;
			path[i][j] = -1;
		}
		dp[i][i] = 0;
		path[i][i] = i;
	}

	fore(i ,1 , m){
		int u , v ,w;
		cin>>u>>v>>w;
		if(dp[u][v] < w)
			continue;
		dp[u][v] = dp[v][u] = w;
		path[u][v] = v;
		path[v][u] = u;
	}
	fore(k , 1 , n){
		fore(i ,1 , n){
			fore(j , 1,  n){
				if (i == k)
					continue;
				ll ans = dp[i][k] + dp[k][j];
				if (ans < dp[i][j]){
					dp[i][j] = ans;
					path[i][j] = path[i][k];
				}
				else if (ans == dp[i][j])
				{
					path[i][j] = min(path[i][j] , path[i][k]);
				}
			}
		}
	}
	int q;
	cin>>q;
	while(q--){
		int u , v;
		cin>>u>>v;
		cout<<path[u][v]<<endl;;
	}
}
