#include <bits/stdc++.h>

using namespace std;

string a, b;

bool can(int s_a, int e_a, int s_b, int e_b) {
	bool yes = true;
	int sz = e_a - s_a + 1;
	for (int i = 0; i < sz; i++) {
		yes &= a[i + s_a] == b[i + s_b];
	}
	if (yes) return yes;
	if (sz % 2 == 1) return false;
	return can(s_a, s_a + sz / 2 - 1, s_b + sz / 2, e_b) && can(s_a + sz / 2, e_a, s_b, s_b + sz / 2 - 1) || 
	can(s_a, s_a + sz / 2 - 1, s_b, s_b + sz / 2 - 1) && can(s_a + sz / 2, e_a, s_b + sz / 2, e_b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b;

	cout << (can(0, (int) a.size() - 1, 0, (int) b.size() - 1) ? "YES" : "NO") << endl;

	return 0;
}

