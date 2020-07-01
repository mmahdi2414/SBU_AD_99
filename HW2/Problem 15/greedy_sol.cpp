#include <bits/stdc++.h>
#include <pthread.h>
#include <ext/rope>

#define L(a) (int)((a).size())
#define sqr(x) ((x) * 1ll * (x))
#define vi vector<int>
#define mp make_pair
#define pub push_back
#define pob pop_back
#define ii pair<int, int>
#define vii vector <ii>
#define all(s) (s).begin(),(s).end()
#define fore(i, l ,r) for(int i = (int)l; i <= (int)r; i++)
#define TRACE(x) cerr << #x << " : " << x << endl
#define _ << " - " <<
#define sout cout<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const ld EPS = 1e-9;
const ld PI = acos((ld)-1);
const ll MOD = (ll)1e9 + 7;
const int INF32 = (int)1e9;
const ll INF64 = (ll)1e19;

using namespace std;
using namespace __gnu_cxx;

int n,m,d;
vi dia ;
vi keys;
bool opened[503];
bool havedia[503];
int main() {
	while(cin>>n>>m>>d && (n||m||d)) {

		dia.clear();
		keys.clear();
		fore(i,1,n) {
			opened[i]=false;
			havedia[i] = false;
		}
		fore(i,1,m) {
			int k;
			cin>>k;
			keys.pub(k);
		}
		int jvb = 0;
		fore(i,1,d) {
			int x;
			cin>>x;
			havedia[x] = true;
		}
		sort(all(keys));
		bool f = true;
		int disfirst = 0 ;
		fore(i,1,keys[0]) {
			if(havedia[i]) {
				d--;
				havedia[i] = false;
				if (f) {
					disfirst =i;
					f=false;
				}
			}
		}
		if (!f) {
			int dis = 1 - opened[keys[0]];
			dis += keys[0] - disfirst;
			jvb+=dis;
			opened[keys[0]] = true;
		}
		f = true;
		disfirst = -1 ;
		fore(i,keys[m-1],n) {
			if(havedia[i]) {
				d--;
				disfirst = i;
				havedia[i] = false;
			}
		}
		if(disfirst!=-1) {
			int dis = 1 - opened[keys[m-1]];
			dis += disfirst - keys[m-1];
			jvb+=dis;
			opened[keys[m-1]] = true;
		}
		fore(i,0,m-2) {
			int first = keys[i];
			int sec = keys[i+1];
			dia.clear();
			fore(j,first,sec) {

				if(havedia[j]) {
					dia.pub(j);
				}
			}
			if (dia.size() == 0)
				continue;
			if (dia.size()==1) {
				int di = dia[0];
				int firstdis = 1 -opened[first];
				int secdis = 1 - opened[sec];
				firstdis += (di-first);
				secdis += (sec - di);
				if (firstdis < secdis) {
					jvb += firstdis;
					opened[first] = true;
				} else {
					jvb += secdis;
					opened[sec] = true;
				}
			} else {
				int fromFirst = 1 -opened[first];
				int fromSec = 1 - opened[sec];
				int dismx = 0 ;
				bool secopen  =false;
				fore(j,-1,dia.size()-1) {
					int dis = 0;
					if (j==-1) {
						dismx+= fromFirst + dia[dia.size()-1] - first;
					} else if (j==dia.size()-1) {
						dis+= fromSec + sec - dia[0];
						if (dis<=dismx) {
							secopen = true;
							dismx = dis;
						}
					} else {
						dis += fromSec + fromFirst;
						dis += dia[j] - first ;
						dis += sec - dia[j+1];
						if (dis<=dismx) {
							secopen = true;
							dismx = dis;
						}
					}

				}
				if (secopen)
					opened [sec] = true;
				jvb+=dismx;
			}
		}
		cout<<jvb<<endl;
	}
	return 0;
}