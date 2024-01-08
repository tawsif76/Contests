#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int isSubstring(string s1, string s2) {
    // using find method to check if s1 is
    // a substring of s2
    if (s2.find(s1) != string::npos)
        return s2.find(s1);
    return -1;
}

void solve() {
	int n, m; cin >> n >> m;
	string x, y; cin >> x >> y;
	int ans = 0, ok = 0;
	while ((int) x.size() <= (int) y.size()) {
		if ((int) x.size() >= (int) y.size() and isSubstring(y, x) != -1) { ok = 1; break; }
		x = x + x;
		ans++;
	}
	if (isSubstring(y, x) != -1) { cout << ans << "\n"; return; }
	ans++;
	x = x + x;
	if (isSubstring(y, x) == -1) cout << "-1\n";
	else cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
