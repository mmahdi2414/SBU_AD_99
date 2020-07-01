#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ii pair<int, int>
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)

const int MAXN = 1e5 + 5;

int dx[] = {1 , 1 , 1 , -1 , -1 , -1 , 0 , 0};
int dy[] = {-1 , 1 , 0 , -1 , 1 , 0 , 1 , -1};


int n , m , k;

bool visited[MAXN];
vector<int> adj[MAXN];
map<ii , int> traps;
ii arr[MAXN];
bool isleftRight , isUpDown , isUpLeft , isRightDown;
bool isLeft , isRight , isUp , isDown;

inline bool valid(int i , int j){
	if (i < 1 || i > n || j < 1 || j > m)
		return false;
	return true;
}

void dfs(int i){
	if (visited[i])
		return;
	visited[i] = true;
	int x = arr[i].first;
	int y = arr[i].second;
	if (x == 1)
		isUp = true;
	if (x == n)
		isDown = true;
	if (y == 1)
		isLeft = true;
	if (y == m)
		isRight = true;
	for(auto j : adj[i])
		dfs(j);

}

int main(){
	// fastio;
	int t;
	// cin>>t;
	scanf("%d" , &t);
	while(t--){
		traps.clear();
		isleftRight = isUpDown = isUpLeft = isRightDown = false;
		scanf("%d%d%d" , &n , &m , &k);
		fore(i ,1 , k){
			int x , y;
			scanf("%d%d",&x,&y);
			visited[i] = false;
			traps[{x , y}] = i;
			arr[i] = {x , y};
			adj[i].clear();
		}
		fore(i , 1, k){
			int x = arr[i].first;
			int y = arr[i].second;
			fore(j , 0 , 7){
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (!valid(tx , ty))
					continue;
				auto it = traps.find({tx , ty});
				if (it == traps.end())
					continue;
				adj[i].push_back(it->second);
			}
		}
		fore(i ,1 , k){
			isLeft = isRight = isUp = isDown = false;
			dfs(i);
			isleftRight |= isLeft && isRight;
			isUpLeft |= isLeft && isUp;
			isUpDown |= isUp && isDown;
			isRightDown |= isDown && isRight;
			if (isleftRight || isUpDown || isUpLeft || isRightDown){
				printf("Harry will be killed by magical traps within the maze!\n");
				break;
			}
		}
		
		if (!(isleftRight || isUpDown || isUpLeft || isRightDown)){
			printf("Harry will be killed by lord Voldemort!\n");
		}

	}
}
