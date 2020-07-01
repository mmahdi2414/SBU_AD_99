#include <bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)

const int MAXN = 150 + 5;
const int inf = 1e9;

int rGraph[MAXN][MAXN];
int graph[MAXN][MAXN];
int parent[MAXN];
bool visited[MAXN]; 

bool bfs(int s, int t , int V) 
{ 
    memset(visited, 0, sizeof(visited)); 
    queue <int> q; 
    q.push(s); 
    visited[s] = true; 
    parent[s] = -1; 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop(); 
  
        for (int v=0; v<V; v++) 
        { 
            if (visited[v]==false && rGraph[u][v] > 0) 
            { 
                q.push(v); 
                parent[v] = u; 
                visited[v] = true; 
            } 
        } 
    } 
    return (visited[t] == true); 
} 

int fordFulkerson(int s, int t , int V) 
{ 
    int u, v; 
  
    for (u = 0; u < V; u++) 
        for (v = 0; v < V; v++) 
             rGraph[u][v] = graph[u][v]; 

    int max_flow = 0;

    while (bfs(s, t , V)) 
    { 

        int path_flow = inf; 
        for (v=t; v!=s; v=parent[v]) 
        { 
            u = parent[v]; 
            path_flow = min(path_flow, rGraph[u][v]); 
        } 

        for (v=t; v != s; v=parent[v]) 
        { 
            u = parent[v]; 
            rGraph[u][v] -= path_flow; 
            rGraph[v][u] += path_flow; 
        } 

        max_flow += path_flow; 
    } 
  
    return max_flow; 
} 

inline void add_edge(int u , int v , int c){
	graph[u][v] = c;
}

string s;
string in[MAXN];
int n;
string sol ="";
int cnt[30];

int flow(int idx){
	int src = 0;
	int sink = n + 27;
	memset(graph , 0 , sizeof(graph));
	fore(i, idx + 1, n-1){
		add_edge(src , i + 1 , 1);
		fore(j,0,in[i].size()-1){
			add_edge(i + 1, in[i][j] -'a'+1 + n , 1);
		}
	}
	fore(i,1,26){
		add_edge(i + n , sink , cnt[i-1]);
	}
	return fordFulkerson(src , sink , sink + 1);
}


int main(){
	cin>>s;
	n = s.size();
	fore(i,0,n-1){
		cnt[s[i]-'a']++;
		cin>>in[i];
		sort(in[i].begin(), in[i].end());
	}

	fore(i,0,n-1){
		bool ok = false;
		fore(j,0,in[i].size()-1){
			if (cnt[in[i][j]-'a']==0)
				continue;
			cnt[in[i][j]-'a']--;
			if (flow(i) == n - i - 1){
				ok = true;
				sol+=in[i][j];
				break;
			}
			cnt[in[i][j] - 'a']++;
		}
		if(!ok){
			return cout<<"NO SOLUTION"<<endl , 0;
		}
	}
	cout<<sol<<endl;
}