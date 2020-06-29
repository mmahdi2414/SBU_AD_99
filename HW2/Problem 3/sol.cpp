#include <bits/stdc++.h>

using namespace std;


#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)
#define forn(i, l, r) for(int i = (int)l; i >= (int)r; i--)


const int MAXN = 1e5 + 5;
const int INF = 2e9;

int n;
int arr[MAXN];
int mxL[MAXN] , mnR[MAXN];
int main(){
	cin>>n;
	fore(i , 1, n){
		cin>>arr[i];
		mxL[i] = max(arr[i] , mxL[i - 1]);
	}
	mnR[n + 1] = INF;
	forn(i , n , 1){
		mnR[i] = min(mnR[i + 1] , arr[i]);
	}
	int res = 0;
	fore(i , 1 , n)
	{
		if (mxL[i] <= mnR[i + 1])
			res++;	
	}
	cout<<res<<endl;
}