#include <bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)

const int MAXN = 2e3 + 5;

int dp[MAXN][MAXN][2];
int l , r , h;
int n;
int arr[MAXN];

inline bool isOk(int j){
	return ( l <= j && j <= r);
}

int solve(int i , int j , int k){
	if (i == n + 1)
	{
		return 0;
	}
	if (dp[i][j][k] != -1)
		return dp[i][j][k];
	if (k){
		int t = arr[i] + j;
		t%=h; 
		dp[i][j][k] = max(solve(i + 1 , t ,0)  , solve(i + 1 , t , 1)) + isOk(t);
	}
	else{
		int t = arr[i] + j - 1 + h;
		t%=h; 
		dp[i][j][k] = max(solve(i + 1 , t ,0)  , solve(i + 1 , t , 1)) + isOk(t);
	}
	return dp[i][j][k];
}

int main(){
	cin>>n>>h>>l>>r;
	fore(i ,1 , n){
		cin>>arr[i];
	}
	memset(dp , -1 , sizeof dp);
	cout<<max(solve(1 , 0 , 1) , solve(1 , 0 , 0))<<endl;
}