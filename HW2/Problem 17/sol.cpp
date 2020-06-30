#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)


const int maxn = 1e5 + 5;
const ll mod = 7340033ll;

ll dp[maxn][2][2][2][3];
int n;

ll solve(int i, int can1 , int can2 , int can3 , int ki){
	int can[]={can1 , can2 , can3};
	if (can[ki] != (i % 2))
		return 0;
	if (i == 1)
		return 1;
	if (~dp[i][can1][can2][can3][ki])
		return dp[i][can1][can2][can3][ki];
	dp[i][can1][can2][can3][ki] = 0;
	can[ki] = 1 - can[ki];
	fore(p ,0 , 2){
		dp[i][can1][can2][can3][ki] += solve(i - 1, can[0] , can[1] , can[2] , p);
	}
	return dp[i][can1][can2][can3][ki] %= mod;
}

int main(){
	memset(dp , -1 , sizeof dp);
	cin>>n;
	if (n % 2){
		cout<<(solve(n , 1 , 1 , 0 , 0) + solve(n , 1 , 1 , 0, 1)) % mod<<endl;
	}
	else {
		cout<<solve(n , 1 , 1 , 0 , 2)<<endl;
	}
	
}