#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	LL ara[n + 1];
	bool eve = 0, odd = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> ara[i];
		if (ara[i] & 1) odd = 1;
		else eve = 1;
	}
	if (odd and eve) {
		cout << "2\n";
		return;
	}
	
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
