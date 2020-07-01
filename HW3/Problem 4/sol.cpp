#include <bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(auto i = l; i <= r; i++)

const int maxn = 1e6 + 5;


int dp[(1 << 20) + 5];
int arr[25][25];
int n;
struct node
{
	int i, j , k;
	void print(){
		cout<<i <<" "<<j <<" "<<k<<endl;
	}
};
node path[(1<<20) + 5];

inline bool isOn(int state , int i){
	if (state & (1 << (i - 1)))
		return true;
	return false;
}

inline int off(int state , int i){
	return state & (~(1 << (i - 1)));
}

inline int val(int i , int j , int k){
	return arr[i][j] + arr[i][k] + arr[j][k];
}

int solve(int state){
	if (__builtin_popcount(state) < 3){
		return 0;
	}
	if (~dp[state])
		return dp[state];
	dp[state] = 0;
	fore(i ,1 , n){
		if (!isOn(state , i))
			continue;
		fore(j , i + 1, n){
			if (!isOn(state , j))
				continue;
			fore(k , j + 1, n){
				if (isOn(state , k)){
					int tmp = off(state , i);
					tmp = off(tmp , j);
					tmp = off(tmp , k);
					int ans = solve(tmp) + val(i , j , k);
					if (ans > dp[state]){
						dp[state] = ans;
						path[state] = {i , j , k};
					}
				}
			}
		}
	}
	return dp[state];
}
void print(int state){
	if (__builtin_popcount(state) < 3)
		return;
	path[state].print();
	int tmp = off(state , path[state].i);
	tmp = off(tmp , path[state].j);
	tmp = off(tmp , path[state].k);
	print(tmp);
}
int main(){
	cin>>n;
	fore(i ,1 , n){
		fore(j ,1 , n){
			cin>>arr[i][j];
		}
	}
	memset(dp , -1 , sizeof dp);
	cout<<solve((1 << n) - 1)<<endl;
}