#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)

const int MAXN = 1e2 + 5;
const int MAXP = 10 + 5;
const int MOD = 100000000;

int n , m , p , q;

int dp[MAXN][MAXN][MAXP][MAXP][2];// 0 red 1 blue

int solve(int numB , int numR , int b , int r , bool isBlue){
	if (b > p || r > q || numR < 0 || numB < 0)
		return 0;
	if (!numB && !numR)
		return 1;
	if (~dp[numB][numR][b][r][isBlue])
		return dp[numB][numR][b][r][isBlue];

	dp[numB][numR][b][r][isBlue] = 0;
	if (isBlue){
		if (numR)
			dp[numB][numR][b][r][isBlue] = solve(numB - 1 , numR , b + 1 , 0, 0) ;
		if (numB)
			dp[numB][numR][b][r][isBlue] += solve(numB - 1 , numR , b + 1 , 0 , 1);
	}
	else{
		if (numR)
			dp[numB][numR][b][r][isBlue] = solve(numB , numR - 1 , 0 , r + 1 , 0);
		if (numB)
			dp[numB][numR][b][r][isBlue] += solve(numB , numR - 1 , 0 , r + 1 , 1);
	}
	return dp[numB][numR][b][r][isBlue]%=MOD;
}

int main()
{
	memset(dp , -1 , sizeof dp);
	cin>>n>>m>>p>>q;
	cout<<(solve(n , m , 0 , 0 , 1) + solve(n , m , 0 , 0, 0))%MOD<<endl;
}