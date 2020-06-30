#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)

const int MAXN = 1e5;

vector<int> nums;
int dp[MAXN + 5][2];


ll x = 65539;
int a = 65539;

int M = (1ll << 31) - 1 ;


ll randominteger (){
	ll xx = (a * x);
	if (xx <= 0)
		xx+=MAXN;
	xx%=MAXN;
	x = xx;
	return x;
}

void init(){
	memset(dp, -1, sizeof dp);
	fore(i ,1 , 100){
		nums.push_back(randominteger() % MAXN);
	}
}

int solve(int n , int turn){
	if (n == 0){
		return 1 - turn;
	}
	if(n < 0)
		return turn;
	if (~dp[n][turn]) return dp[n][turn];
	dp[n][turn] = 1 - turn;
	fore(i ,0 , nums.size() - 1){
		if (solve(n - nums[i] , 1 - turn) == turn)
			return dp[n][turn] = turn;
	}
	return dp[n][turn];
}

bool can(int n){
	if (solve(n , 1))
		return true;
	return false;
}

int main(){
	int n;
	cin>>n;
	init();
	string res = "NO";
	if(can(n))
		res = "YES";
	cout<<res<<endl;
}