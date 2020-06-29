#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int par[MAXN], col[MAXN];

int root(int v) {
	return par[v] < 0 ? v : par[v] = root(par[v]);
}

void merge(int v,int u) {
	if ((v = root(v)) == (u = root(u)))
		return;
	if (par[v] < par[u])
		swap(v, u);
	par[u] += par[v];
	par[v] = u;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		par[i] = -1, col[i] = i;

	for (int i = 0; i < m; i++) {
		int type;
		cin >> type;
		if (type == 2) {
			int idx;
			cin >> idx;
			idx--;
			idx = root(idx);
			cout << col[idx] + 1 << '\n';
		} else {
			int v, u;
			cin >> v >> u;
			v--, u--;
			int c = col[root(u)];
			merge(v, u);
			col[root(u)] = c;
		}
	}

	return 0;
}