#include <iostream>
using namespace std;
const int maxn=300;
int n, m, source, destination;
long long int dist[maxn][maxn];
long long int price[maxn];
long long int dp[maxn];

void initialize();
void read();
void preprocess();

int main(){
	initialize();
	read();
	preprocess();
	dp[source]=0;
	for(int counter=0; counter<n; counter++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				dp[i]=min(dp[i], dp[j]+dist[j][i]*price[j]);
	cout<<dp[destination]<<endl;
	return 0;
}

void initialize(){
	for(int i=0; i<maxn; i++)
		for(int j=0; j<maxn; j++)
			dist[i][j]=1000*1000*1000;
	long long int inf=1000*1000*1000;
	inf*=1000*1000*1000;
	for(int i=0; i<maxn; i++)
		dp[i]=inf;
}

void read(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int v, u, w;
	for(int i=0; i<m; i++){
		cin>>v>>u>>w;
		v--;
		u--;
		dist[u][v]=dist[v][u]=w;
	}
	for(int i=0; i<n; i++)
		cin>>price[i];
	cin>>source>>destination;
	source--;
	destination--;
}

void preprocess(){
	for(int i=0; i<n; i++)
		dist[i][i]=0;
	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
}

