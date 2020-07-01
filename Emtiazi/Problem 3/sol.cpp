//
// Created by AmS on 12/11/2018.
//
#include <bits/stdc++.h>

using namespace std;
#define fore(i,l,r) for(int i = l ; i<=r;i++)
#define ii pair<int,int>
#define vii vector<ii>
#define TRACE(x) cout<<#x<<" : "<<x<<endl;

char matris[105][105];
int timing [105][105];
int dis[105][105];
vii v;
int const inf = (int)(1e9);
int n,m,k;
ii s;
ii t;
int dx[]={1,1,-1,-1,0,0,1,-1};
int dy[]={1,-1,1,-1,1,-1,0,0};
void bfst(ii x){
    queue<ii> q ;
    timing[x.first][x.second] = 0;
    q.push(x);
    while (!q.empty()){
        ii u = q.front();
        q.pop();
        int i = u.first;
        int j = u.second;

        fore(kk,0,7){
            int tx = i + dx[kk];
            int ty = j + dy[kk];
            if (timing[i][j] + k < timing[tx][ty]){
                timing[tx][ty] = timing[i][j] + k;
                q.push({tx,ty});
            }
        }
    }
}
void bfss(){
    queue<ii> q;
    dis[s.first][s.second] = 0;
    q.push(s);
    while (!q.empty()){
        ii u = q.front();
        q.pop();
        int i = u.first;
        int j = u.second;
        fore(kk,4,7){
            int tx = i + dx[kk];
            int ty = j + dy[kk];
            if (dis[i][j] + 1 >= timing[tx][ty])
                continue;
            if (dis[i][j] + 1 < dis[tx][ty]){
                dis[tx][ty] = dis[i][j]+1;
                q.push({tx,ty});
            }
        }
    }
    if (dis[t.first][t.second] == inf){
        cout<<"Impossible"<<endl;
    }
    else{
        cout<<dis[t.first][t.second]<<endl;
    }
}
int main(){
    while(true)
    {
        cin>>n>>m>>k;
        if (n==0 && m==0 && k==0)
            break;
        v.clear();
        fore(i,1,n){
            fore(j,1,m){
                dis[i][j] = inf;
                timing[i][j] = inf;
                cin>>matris[i][j];
                if (matris[i][j] == 'f')
                    v.push_back({i,j});
                else if (matris[i][j]=='t'){
                    t.first = i;
                    t.second = j;
                }
                else if (matris[i][j] == 's'){
                    s.first = i;
                    s.second = j;
                }
            }
        }
        fore(kk,1,v.size()){
            bfst(v[kk-1]);
        bfss();
    }
}
