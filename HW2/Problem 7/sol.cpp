#include <bits/stdc++.h>

using namespace std;

#define fore(i , l , r) for(auto i = l ; i <= r ; i++)

const int MAXN = 10 + 5;

int n , m;
int c;
int grid[MAXN][MAXN];
int color[MAXN];
int main(){
	cin>>n>>m>>c;
	fore(i , 1, c){
		cin>>color[i];
	}
	int row = n;
	int col = 1;
	int dir = 1;
	fore(i ,1 , c){
		while(color[i]--){
			grid[row][col] = i;
			col += dir;
			if (col == m + 1 || col == 0)
			{
				dir *= -1;
				col += dir;
				row--;
			}
		}
	}
	fore(i , 1, n){
		fore(j , 1, m){
			cout<<grid[i][j];
		}
		cout<<endl;
	}
}

