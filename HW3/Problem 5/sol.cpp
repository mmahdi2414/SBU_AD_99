#include <bits/stdc++.h>

using namespace std;



#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)

int perm[21];
bool visited[20];

int n;
int mn,mx;

void permute(int st , int l , int r , int ans){
	if (ans > r)
		return;
	
	if (st == n + 1){
		if(ans < l)
			return;
		fore(i , 1, n){
			cout << perm[i] << " ";
		}
		cout<<"\n";
		return;
	}
	int mx = ans;
	int mn = ans;
	int stt = st;
	int stt1 = st;
	fore(i , 1 , n){
		if (!visited[i])
		{
			mn += max(0 , i - stt);
			mx += max(0 , i - stt1);
			stt++;
			stt1--;
		}
	}
	if (mx < l || mn > r){
		return;
	}
	fore(i , 1 , n){
		if(!visited[i]){
			perm[st] = i;
			visited[i] = true;
			permute(st + 1 , l , r , ans + max(0 , perm[st] - st));
			visited[i]=0;
		}
	}
}

int main(){
	fastio;
	int l , r;
	cin >> n >> l >> r;
	permute(1 , l , r , 0);	
}