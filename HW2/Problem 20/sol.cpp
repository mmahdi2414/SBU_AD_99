#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)
const int MAXN = 2e3 + 5;
const int INF = 1e9;
int n , m , p , q;
int dp[MAXN][MAXN];
int w[MAXN];
int val[MAXN];
int idx = 0;

int solve(int i , int weight){
	if (weight < 0)
		return -INF;
	if (i == 0)
		return 0;
	if (~dp[i][weight])
		return dp[i][weight];
	return dp[i][weight] = max(solve(i - 1, weight) , solve(i - 1 , weight - w[i]) + val[i]);
}

int main(){
	memset(dp , -1 , sizeof dp);
	cin>>n>>m;
	cin>>p>>q;
	fore(i ,1 , m){
		int a , b , c , d;
		cin>>a>>b>>c>>d;
		while(a >= b){
			w[++idx] = c;
			val[idx] = d;
			a -= b;
		}
	}
	int temp = n;
	while(temp >= p){
		w[++idx] = p;
		val[idx] = q;
		temp -= p;
	}

	cout<<solve(idx , n)<<endl;

}