#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	char d; cin >> d;
	string s; cin >> s;
	int pos = n;
	for (int i = 0; i < n; ++i) {
		if (s[i] < d) {
			pos = i;
			break;
		}
	}
	for (int i = 0; i < pos; ++i) cout << s[i];
	cout << d;
	for (int i = pos; i < n; ++i) cout << s[i];
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
