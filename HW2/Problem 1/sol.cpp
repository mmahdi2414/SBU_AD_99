#include <bits/stdc++.h>

using namespace std;

#define fore(i , l , r) for(auto i = l ; i <= r ; i++)


int n , x;
vector<int> arr;

int main(){
	cin>>n>>x;
	fore(i ,1 , n){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	fore(i , 1 , n - 1){
		if (arr[i] + arr[i - 1] > x)
			return cout<<i<<endl , 0 ;
	}
	cout<<n<<endl;
}