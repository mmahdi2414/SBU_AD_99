#include<bits/stdc++.h>
using namespace std;
 
#define fore(i,l,r) for (int i = l; i <= r; ++i)
#define ll long long
#define ld long double
 
string number ;
int n;
struct Box
{
	ll kilo  , num , id;
};
ll power[19];
bool operator<(Box b1 , Box b2){
	return power[b1.kilo] * b1.num < power[b2.kilo] * b2.num; 
}
vector<Box> boxes[20];
vector<int> ans;
int main(){
	power[0]  = 1;
	fore(i,1,18){
		power[i] = power[i-1] * 10ll;
	}
	cin>>number>>n;
	fore(i,1,n){
		long long x  ,y;
		cin>>x>>y;
		boxes[x].push_back({x, y , i});
	}
 
	ll temp = 0;
	int res = 0;
	priority_queue<Box> q;
	fore(i,0,number.size()-1){

		for(auto b : boxes[i]){
			q.push(b);
		}

		ll adad = (ll)(number[number.size()- i-1] - '0') * power[i];

		while (!q.empty() && temp < adad ){
			Box b = q.top();
			q.pop();
			ans.push_back(b.id);
			res++;
			temp+= power[b.kilo] * b.num;
		}
		temp -= adad;
		if (temp < 0){
			return cout<<-1<<endl , 0;
		}
	}
	cout<<res<<endl;
	bool first = true;
	for(auto it : ans){
		if (!first){
			cout<<" ";
		}
		first = false;
		cout<<it;
	}
	cout<<endl;
 
}