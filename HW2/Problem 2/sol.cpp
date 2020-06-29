#include <bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)
#define forn(i, l, r) for(int i = (int)l; i >= (int)r; i--)

const int maxn = 1e5 + 5;


int n;
int arr[maxn];
int print[maxn];
vector<int> c;
vector<int> ans;

int main(){
	cin>>n;
	fore(i , 1, n){
		cin>>arr[i];
	}
	int mx = 1;
	c.push_back(arr[1]);
	print[1] = 0;
	fore(i, 2 , n){
		int x = arr[i];
		int idx = upper_bound(c.begin(), c.end() , x) - c.begin();
		if (idx == c.size())
		{
			c.push_back(arr[i]);
			print[i] = c.size() - 1;
			mx = i;
			continue;
		}	
		c[idx] = arr[i];
		print[i] = idx;
	}
	int p = print[mx];
	forn(i , mx , 1){
		if(print[i] == p){
			ans.push_back(i);
			p--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout<<ans.size()<<endl;
	for(auto it : ans){
		cout<<it<<" ";
	}
	cout<<endl;
}