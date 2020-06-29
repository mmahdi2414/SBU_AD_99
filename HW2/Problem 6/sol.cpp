#include <bits/stdc++.h>

using namespace std;

#define fore(i , l , r) for(auto i = l ; i <= r ; i++)

const int MAXN = 1e5 + 5;

int m , s , c;
vector<int> arr, nums;

int main(){
	cin>>m>>s>>c;
	fore(i , 1, c){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	auto ip = unique(arr.begin(), arr.end()); 
    arr.resize(distance(arr.begin(), ip)); 
    int ans = arr.size();
    fore(i , 1 , arr.size() - 1){
    	if (arr[i] - arr[i - 1] != 1){
    		nums.push_back(arr[i] - arr[i - 1] - 1);
    	}
    }
    sort(nums.begin(), nums.end());
    fore(i , 0 , int(nums.size()) - m){
    	ans+=nums[i];
    }
    cout<<ans<<endl;
}