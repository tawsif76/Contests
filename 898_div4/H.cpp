#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 2e5 + 5;

bool vis[N];
int dep[N], par[N], disA[N], disB[N];
vector<int> adj[N];
int c1, c2;

void dfs(int node, int p) {
	vis[node] = 1;
	par[node] = p;
	dep[node] = dep[p] + 1;
	for (int u : adj[node]) {
		if (!vis[u]) dfs(u, node);
		else if (dep[u] <= dep[node] and u != p) c1 = node, c2 = u;
	}
}

vector<int> find() {
	vector<int> v;
	while (c1 != c2) {
		v.push_back(c1);
		c1 = par[c1];
	}
	v.push_back(c2);
	return v;
}

// who = 1 = a

void bfs(int src, bool who) {
	if (who) disA[src] = 0;
	else disB[src] = 0;
	queue<int> Q;
	vis[src] = 1;
	Q.push(src);
	while (!Q.empty()) {
		int node = Q.front(); Q.pop();
		for (int u : adj[node]) {
			if (!vis[u]) {
				Q.push(u);
				vis[u] = 1;
				if (who) disA[u] = disA[node] + 1;
				else disB[u] = disB[node] + 1;
			}
		}
	}
}	

void solve() {
	int n, a, b; cin >> n >> a >> b;
	for (int i = 1; i <= n; ++i) adj[i].clear(), dep[i] = vis[i] = disA[i] = disB[i] = 0;
	for (int i = 1; i <= n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	c1 = c2 = dep[0] = -1;
	dfs(1, 0);
	assert(c1 != -1);
	vector<int> cyc = find();
	memset(vis, 0, sizeof vis);
	bfs(a, 1);
	memset(vis, 0, sizeof vis);
	bfs(b, 0);
	bool ok = 0;
	for (auto u : cyc) ok |= (disB[u] < disA[u]);
	cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
