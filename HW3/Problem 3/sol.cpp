#include <bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)

const int maxn = 10;

int n , m , k;
int ans = 0;
int col[maxn];

bool safe(int i ,int j){
	fore(row , 1, i - 1){
		if(col[row] == 0)
			continue;
		if (col[row] == j)
			return false;
		if(row - col[row] == i - j)
			return false;
		if (row + col[row] == i + j)
			return false;
	}
	return true;
}

void bt(int i , int num){
	if (num > k)
		return;
	if (num + n - i + 1 < k)
		return;
	if (i == n + 1){
		if(num == k){
			// LOG1DArray(col , n);
			ans++;
		}
		return;
	}

	fore(j ,1 , m){
		if (safe(i , j))
		{
			col[i] = j;
			bt(i + 1, num + 1);
		}
	}
	col[i] = 0;
	bt(i + 1 , num);
}
int main(){
	cin>>n>>m>>k;
	bt(1 , 0);
	cout<<ans<<endl;
}