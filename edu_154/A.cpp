#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	string s; cin >> s;
	char ch;
	for (int i = 0; i < (int) s.size(); ++i) {
		if (s[i] == '3' or s[i] == '1') { ch = s[i]; break; }
	}
	if (ch == '3') cout << 31 << "\n";
	else cout << 13 << "\n"; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
