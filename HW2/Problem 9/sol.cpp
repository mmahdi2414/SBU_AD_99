#include <bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)


const int MAXN = 1e5 + 5;

int n;
int arr[MAXN];

int main(){

    cin>>n;
    fore(i,1,n){
        cin>>arr[i];
    }
    vector<int> res;
    bool flag = true;
    res.push_back(arr[1]);
    fore(i,2,n){
        if (flag){
            if (arr[i] <= res.back())
            {
                res.pop_back();
                res.push_back(arr[i]);
            }
            else{
                res.push_back(arr[i]);
                flag = false;
            }
        }
        else{
            if (arr[i] >= res.back())
            {
                res.pop_back();
                res.push_back(arr[i]);
            }
            else{
                res.push_back(arr[i]);
                flag = true;
            }
        }
    }
    cout<<res.size()<<endl;
}