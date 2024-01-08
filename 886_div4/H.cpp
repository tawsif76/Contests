#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 2e5 + 5;

vector<pair<int, int > > adj[N];
int vis[N];
LL cord[N];

bool dfs(int node, LL cur) {
	vis[node] = 1;
	cord[node] = cur;
	//cerr << node << " " << cord[node] << "\n";
	bool ok = 1;
	for (auto [u, w] : adj[node]) {
		if (!vis[u]) ok &= dfs(u, cord[node] + w);
		else if (w + cord[node] != cord[u]) {
			return 0;
		}
	}
	return ok;
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) vis[i] = 0, cord[i] = 0, adj[i].clear();
	for (int i = 1; i <= m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, -w});
	}
	bool ok = dfs(1, 1);
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			ok &= dfs(i, 1);
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
