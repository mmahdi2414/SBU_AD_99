#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)
#define ii pair<int, int>

const int maxn = 1e6 + 5;

int arr[maxn];
int n;
ii st[maxn * 4];

inline int getMid(int s, int e) { return s + (e -s)/2; }

ii getMax(int begin, int end, int l, int r, int index)  
{   
    if (l <= begin && r >= end)  
        return st[index]; 
    if (end < l || begin > r)  
        return {0 , 0}; 
    int mid = getMid(begin, end);  
    return max(getMax(begin, mid, l, r, 2*index+1),  
                getMax(mid+1, end, l, r, 2*index+2));  
} 


int findMax(int l , int r){
	 return getMax(0 , n - 1, l, r, 0).second;
}

ii consttruct(int ss, int se, int si)  
{  
    if (ss == se)  
    {  
        return st[si] = {arr[ss] , ss};
    }  
    int mid = getMid(ss, se);  
    st[si] = max(consttruct(ss, mid, si*2+1),  
                    consttruct(mid+1, se, si*2+2));  
    return st[si];  
}  


pair<ll , int> solve(int l , int r){
	if (l > r)
		return {0 , -1};
	if (l == r)
	{
		return {0 , arr[l]};
	}
	int mid = findMax(l , r);
	auto res1 = solve(l , mid - 1);
	auto res2 = solve(mid + 1 , r);
	ll res = 0;
	if (~res1.second){
		res+=res1.first;
		res+=arr[mid]-res1.second;
	}
	if (~res2.second){
		res+=res2.first;
		res+=arr[mid]-res2.second;
	}
	return {res , arr[mid]};

}
int main(){
	cin>>n;
	fore(i , 1, n){
		cin>>arr[i - 1];
	}
	consttruct(0, n-1, 0); 
	cout<<solve(0 , n - 1).first<<endl;
}

