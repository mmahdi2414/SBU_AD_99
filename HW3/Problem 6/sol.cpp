#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ii pair<int, int>
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)

const int maxn = 1e5 + 5;

struct Node
{
	int idx , solve , penalty;
	void update(int p){
		penalty += p;
		solve++;
	}
};
bool operator< (Node a , Node b){
	pair<int , ii> aa = {-a.solve , {a.penalty , a.idx}};
	pair<int , ii> bb = {-b.solve , {b.penalty , b.idx}};
	return aa < bb;
}
int n , m;
set<Node> s;
Node students[maxn];
int main(){
	fastio;
	cin>>n>>m;	
	fore(i ,1 , n){
		students[i] ={i , 0 , 0};
	}
	while(m--){
		int number , penalty;
		cin>>number>>penalty;
		if (number != 1){
			if (students[number] < students[1]){
				s.erase(students[number]);
			}
			students[number].update(penalty);
			if (students[number] < students[1]){
				s.insert(students[number]);
			}
		}
		else{
			students[number].update(penalty);
			auto it = s.lower_bound(students[number]);
			s.erase(it , s.end());
		}
		cout<<s.size() + 1<<endl;
	}
}