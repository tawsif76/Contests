#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, k; cin >> n >> k;
	int ara[n + 1];
	vector<int> pos[k + 2];
	for (int i = 1; i <= n; ++i) { cin >> ara[i]; pos[ara[i]].push_back(i); }
	int ans = INT_MAX;
	for (int i = 1; i <= k; ++i) {
		if ((int) pos[i].size() == 0) continue;
		multiset<int> ms;
		ms.insert(pos[i][0] - 1);
		ms.insert(n + 1 - pos[i][(int) pos[i].size() - 1] - 1);
		for (int j = 0; j < (int) pos[i].size() - 1; ++j) {
			ms.insert(pos[i][j + 1] - pos[i][j] - 1);
		}
		// if (i == 1) {
		// 	//cerr <<n << " " << pos[i][(int) pos[i].size() - 1]<< endl;
		// 	for (auto u : ms) cerr << u << " ";
		// }
		int big = *prev(ms.end());
		ms.erase(ms.find(big));
		int half = big / 2;
		if (big & 1) ms.insert(half);
		else if (half) {
			ms.insert(half);
			ms.insert(half - 1);
		}
		int now = *prev(ms.end());
		ans = min(ans, now);
		//if (ans == 1) cerr << i << endl;
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
