#include <bits/stdc++.h>

using namespace std;

#define fore(i , l , r) for(auto i = l ; i <= r ; i++)


const int MAXN = 1e3 + 5;

const int dx[]={1 , -1 , 0 , 0};
const int dy[]={0 , 0 , 1 , -1};

int n , m , q;
int grid[MAXN][MAXN];
int res = 0;

#define OCEAN 0
#define LAND 1
#define HIT -1


int main(){
	cin>>n>>m>>q;
	fore(i , 1, n){
		fore(j ,1 , m){
			cin>>grid[i][j];
			res += grid[i][j];
		}
	}

	while(q--){
		int x , y;
		cin>>x>>y;
		if (grid[x][y] != OCEAN){
			res -= grid[x][y] == LAND;
			grid[x][y] = HIT;
			fore(i , 0 , 3){
				int tx = x  + dx[i];
				int ty = y  + dy[i];
				if (grid[tx][ty] == LAND)
				{
					res--;
					grid[tx][ty] = HIT;
				}
			}
		}
		cout<<res<<endl;
	}
}