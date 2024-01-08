#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	string a, b; cin >> a >> b;
	for (int i = 1; i < (int) a.size(); ++i) {
		if (a[i] == b[i] and a[i - 1] == b[i - 1] and a[i] == '1' and a[i - 1] == '0') {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
