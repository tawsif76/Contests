#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	sort(ara + 1, ara + n + 1);
	vector<int> c, b;
	for (int i = 1; i <= n; ++i) {
		if (ara[i] == ara[n]) c.push_back(ara[i]);
		else b.push_back(ara[i]);
	}
	if (c.empty() or b.empty()) cout << "-1\n";
	else {
		cout << b.size() << " " << c.size() << "\n";
		for (int i : b) cout << i << " ";
		cout << "\n";
		for (int i : c) cout << i << " ";
		cout << "\n";
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
