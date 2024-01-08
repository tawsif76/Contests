#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	string s; cin >> s;
	int n = (int) s.size();
	int rtA[n + 2]{}, ltA[n + 2]{}, cnt = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == 'B') rtA[i] = cnt, cnt = 0;
		else cnt++, rtA[i] = cnt;
	}
	cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'B') ltA[i] = cnt, cnt = 0;
		else cnt++, ltA[i] = cnt;	
	}
	int preAB[n + 1]{}, sufBA[n + 2]{};
	for (int i = 0; i < n; ++i) {
		if (i - 1 < 0) continue;
		if (s[i] == 'B') preAB[i] = preAB[i - 1] + ltA[i]; 
		else preAB[i] = preAB[i - 1];
	} 
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == 'B') sufBA[i] = sufBA[i + 1] + rtA[i];
		else sufBA[i] = sufBA[i + 1];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'B') ans = max(ans, preAB[i] + sufBA[i + 1]);
	}
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'B' and i - 1 < 0) { ans = max(ans, sufBA[i]); continue; } 
		if (s[i] == 'B') ans = max(ans, preAB[i - 1] + sufBA[i]);
	}
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
