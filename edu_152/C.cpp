#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, m; cin >> n >> m;
	string s; cin >> s;
	int rtOne[n + 1], lftzero[n + 1];
	int oneIdx = n - 1, zeroIdx = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == '1') oneIdx = i;
		rtOne[i] = oneIdx;
	}
	for (int i = 0; i < n; ++i) {	
		if (s[i] == '0') zeroIdx = i;
		lftzero[i] = zeroIdx;
	}
	int ans = 0, ori = 0;
	set<pair<int, int > > st;
	for (int i = 1; i <= m; ++i) {
		int L, R; cin >> L >> R;
		--L, --R;
		oneIdx = rtOne[L], zeroIdx = lftzero[R];
		if (zeroIdx <= oneIdx) ori = 1;
		else st.insert({oneIdx, zeroIdx});
	}
	cout << (int) st.size() + ori << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
