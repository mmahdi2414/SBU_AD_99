#include <bits/stdc++.h>

using namespace std;

#define fore(i , l , r) for(auto i = l ; i <= r ; i++)


priority_queue<int> q;
int n;

int main(){
	cin>>n;
	fore(i , 1, n){
		int x;
		cin>>x;
		q.push(x);
	}
	while(q.size() > 1){
		int x = q.top();
		q.pop();
		int y = q.top();
		q.pop();
		int diff = abs(x - y);
		if (diff)
			q.push(diff);
	}
	if (q.size())
		cout<<q.top()<<endl;
	else cout<<0<<endl;
}