#include <bits/stdc++.h>

using namespace std;
using LL = long long;

vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19};
vector<int> adj[30];
bool vis[30];

void dfs(int node) {
	vis[node] = 1;
	for (int u : adj[node]) {
		if (!vis[u]) dfs(u);
	}
}

void solve() {
	for (int i = 0; i < 30; ++i) adj[i].clear(), vis[i] = 0;
	int n; cin >> n;
	vector<int> cur;
	for (int i : prime) if (i <= n) cur.push_back(i);
	for (int mask = 0; mask < (1 << (int) cur.size()); ++mask) {
		vector<int> H;
		for (int i = 0; i < (int) cur.size(); ++i) {
			if (mask & (1 << i)) H.push_back(cur[i]);
		}
		for (int p : H) {
			for (int k : H) {
				if (p != k and p * k <= n) {
					adj[k].push_back(p);
					adj[p].push_back(k);
				}
			}
		}
	} 

	int ans = 0;

	for (int i : cur) {
		if (!vis[i]) dfs(i), ans++;
	}

	cout << ans - 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
