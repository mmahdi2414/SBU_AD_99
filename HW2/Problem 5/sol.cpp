#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fore(i , l , r) for(auto i = l ; i <= r ; i++)

const int MAXN = 1e2 + 5;
const ll INF = 1e18;

int n;
int arr[MAXN];
ll sum[MAXN];
ll dp[MAXN][MAXN];


inline ll getSum(int l , int r){
	return sum[r] - sum[l - 1];
}


int main(){
	cin>>n>>n;
	fore(i , 1, n){
		cin>>arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	fore(i , 1, n){
		fore(j , 1, n){
			dp[i][j] = INF;
		}
		dp[i][i] = 0;
	}
	fore(l , 2 , n){
		fore(i , 1, n - l + 1){
			int j = i + l - 1;
			fore(k , i , j - 1){
				dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k + 1][j] + getSum(i , j));
			}
		}
	}
	cout<<dp[1][n]<<endl;
}