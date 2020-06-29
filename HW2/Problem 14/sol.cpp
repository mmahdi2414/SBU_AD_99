#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)


const int MAXN = 20;

int n , m , l;
bool grid[MAXN][MAXN];
bool game[MAXN][MAXN];
bool gamecopy[MAXN][MAXN];

const int dx[]={1 , 1 , 1 , -1 , -1 , -1 , 0 , 0};
const int dy[]={1 , -1 , 0 , 1 , -1 , 0 , 1 , -1};

void play(){
	fore(i , 1, n){
		fore(j , 1, m){
			int cnt = 0;
			fore(d, 0 , 7){
				int tx = i + dx[d];
				int ty = j + dy[d];
				if (tx == 0)
					tx = n;
				else if (tx == n + 1)
					tx = 1;
				if (ty == 0)
					ty = m;
				else if (ty == m + 1)
					ty = 1;
				cnt += game[tx][ty];
			}
			if (game[i][j])
			{	
				if (cnt == 2){
					gamecopy[i][j] = true;
					continue;
				}
			}
			if (cnt == 3){
				gamecopy[i][j] = true;
			}
			else {
				gamecopy[i][j] = false;
			}
		}
	}
	fore(i , 1, n){
		fore(j ,1 , m){
			game[i][j] = gamecopy[i][j];
		}
	}
}
bool equal(){
	fore (i ,1 , n){
		fore(j , 1 , m)
		{
			if (grid[i][j] != game[i][j])
				return false;
		}
	}
	return true;
}


int main(){
	fastio;
	cin>>n>>m>>l;
	fore(i ,1 , n){
		fore(j ,1 , m){
			char c;
			cin>>c;
			grid[i][j] = (c == '*');
		}
	}
	int range = 1 << (m * n);
	range--;
	fore(i ,0 , range){
		fore(j , 0,  m * n - 1){
			if (i & (1 << j)){
				game[(j / m) + 1][(j % m )+ 1] = true;
			}
			else{
				game[(j / m) + 1][(j % m) + 1] = false;
			}
		}
		fore(j , 1, l)
		{
			play();
		}
		if(equal()){
			fore(row ,1 , n){
				fore(j ,1, m){
					int p = (row - 1) * m + j - 1;
					if (i & (1 << p)){
						cout<<"*";
					}
					else{
						cout<<".";
					}
				}
				cout<<"\n";
			}
			return 0;
		}
	}
	cout<<"impossible"<<"\n";

}

