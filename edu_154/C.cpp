#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	string s; cin >> s;
	int n = (int) s.size();
	int lastOne = -1, lastDec = -1, lastInc = -1;
	bool have[n + 1];
	bool ok = 1;
	stack<int> curSet;
	for (int i = 0; i < n; ++i) if (s[i] == '1') lastOne = i;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			if (curSet.size() < 2) { ok = 0; break; }
			if (lastInc != -1 and curSet.top() <= lastInc) ok = 0;
			lastDec = curSet.top();

		} else if (s[i] == '1') {
			if (lastDec != -1 and have[lastDec]) ok = 0;
			if (!curSet.empty()) lastInc = curSet.top();

		} else if (s[i] == '+') {
			curSet.push(i);
			have[i] = 1;
		} else {
			if (!curSet.empty()) have[curSet.top()] = 0, curSet.pop();
		}
	}

	cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
