#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	LL ara[n + 1], pre[n + 1]{};
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	sort(ara + 1, ara + n + 1);
	for (int i = 1; i <= n; ++i) pre[i] = ara[i] + pre[i - 1];
	for (int i = 1; i <= n; ++i) {
		cout << pre[n] - pre[i - 1] << " ";	
	}
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
