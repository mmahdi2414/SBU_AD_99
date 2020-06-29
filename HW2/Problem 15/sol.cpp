#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(auto i = l; i <= r; i++)

const int MAXN = 5e2 + 5;

int dp[MAXN][2], n, k, m;
bool has_key[MAXN], has_ball[MAXN];

int main(){
    cin>>n>>k>>m;
    fore(i , 1 ,k){
        int cell;
        cin>>cell;
        has_key[cell] = true;
    }
    fore(i ,1 , m){
        int cell; 
        cin>>cell;
        has_ball[cell] = true;
    }
    dp[0][1] = MAXN;
    fore(i ,1 , n){
        dp[i][0] = has_ball[i] ? MAXN : min(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = min(MAXN, 1 + dp[i-1][1]);
        if(has_key[i])
            for(int j = i; j >= 1; j--)
                dp[i][1] = min(dp[i][1], 1 + i - j + min(dp[j-1][0], dp[j-1][1]));
    }
    cout<<min(dp[n][1], dp[n][0])<<endl;
}