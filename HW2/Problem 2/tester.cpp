#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define ii pair<int, int>
#define LOG(x) cerr << x <<" ";
#define TRACE(x) //cout << #x << " : " << x << endl
#define LOG2DArray(array, n, m) for ( int i = 0; i < n ; i++) { for (int j = 0; j < m; j++) { LOG(array[i][j]); } cout<<endl; } cout<<endl;
#define LOG1DArray(array, n)  for( int i = 0; i < n ; i++){ LOG( array[i]); } cout<<endl<<endl;
#define myFor(i, l, r) for(int i = (int) l;i< (int) r;i++)
#define _ << ":" <<
#define L(a) (int)((a).size())
#define sqr(x) ((x) * 1ll * (x))
#define vi vector<int>
// #define mp make_pair
#define pub push_back
#define pob pop_back
#define vii vector <ii>
#define vs vector <string>
#define all(s) (s).begin(),(s).end()
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; i++)
#define REP(i, n) for (int i = 1; i <= n; i++)

const int maxn = 1e5 + 5;
const int inf = 1e9;
const ld eps = 1e-6;

int n , arr[maxn];
int lis[maxn];
int main(int argc, char const *argv[]){

	ifstream test_in(argv[1]);    
	ifstream test_out(argv[2]);
	ifstream user_out(argv[3]);
    int n;
    test_in>>n;
    fore(i, 1 , n){
        test_in>>arr[i];
    }
    int mine;
    test_out>>mine;
    int yours;
    user_out>>yours;
    if (mine != yours)
        return 1;
    if (mine){
        user_out>>lis[1];
        if (lis[1] < 1 || lis[1] > n)
            return 1;
    }
    fore(i ,2 , mine){
        user_out>>lis[i];

        if (lis[i] < 1 || lis[i] > n)
            return 1;
        if (lis[i] <= lis[i - 1])
            return 1;
        if (arr[lis[i]] < arr[lis[i - 1]])
            return 1;
    }
    string s;
    if (user_out>>s)
        return 1;
    return 0;
}
