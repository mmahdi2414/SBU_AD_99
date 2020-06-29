#include <bits/stdc++.h>

using namespace std;

#define fore(i , l , r) for(auto i = l ; i <= r ; i++)

const int MAXN = 1e3 + 5;

const int dx[]={1 , -1 , 0 , 0};
const int dy[]={0 , 0 , 1 , -1};

int n , m;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int res = 0;

inline bool valid(int i , int j){
	if (i < 1 || i > n || j < 1 || j > m || grid[i][j] == '#')
		return false;
	return true;
}

void dfs(int ux , int uy){
	if (visited[ux][uy])
		return;
	visited[ux][uy] = true;
	res++;
	fore(i , 0 , 3){
		int tx = ux + dx[i];
		int ty = uy + dy[i];
		if (valid(tx , ty))
			dfs(tx , ty);
	}
}

int main(){
	cin>>n>>m;
	fore(i , 1, n){
		fore(j ,1 , m){
			cin>>grid[i][j];
		}
	}
	int exitDoor = 0;
	fore(i , 1, n){
		if (grid[i][m] == '-'){
			dfs(i , m);
			exitDoor++;
		}
	}
	cout<<res - exitDoor<<endl;
}