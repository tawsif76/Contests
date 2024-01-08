#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 2e5 + 4;
bool vis[N];
vector<int> depends[N];
LL cost[N];

LL rec(int cur) {
	if (vis[cur]) return cost[cur];
	LL tot = 0;
	for (auto u : depends[cur]) {
		if (vis[u]) tot += cost[u];
		else tot += rec(u);
	}
	vis[cur] = 1;
	if (depends[cur].size() == 0) tot = cost[cur];
	return cost[cur] = min(cost[cur], tot);	
}

void solve() {
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; ++i) vis[i] = 0, depends[i].clear();
	for (int i = 1; i <= n; ++i) cin >> cost[i];
	for (int i = 1; i <= k; ++i) {
		int x; cin >> x;
		cost[x] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		int sz; cin >> sz;
		for (int j = 1; j <= sz; ++j) {
			int x; cin >> x;
			depends[i].push_back(x);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		else rec(i);
	}
	for (int i = 1; i <= n; ++i) cout << cost[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
