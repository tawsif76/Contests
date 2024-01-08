#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 2e5 + 5;

vector<int> adj[N];
int vis[N], dep[N], par[N], cycSt, cycEnd;

void dfs(int node, int p) {
	vis[node] = 1;
	par[node] = p;
	dep[node] = dep[p] + 1;
	for (int u : adj[node]) {
		if (!vis[u]) dfs(u, node);
		else if (dep[u] <= dep[node]) {
			if (cycSt == -1 and cycEnd == -1) cycSt = node, cycEnd = u;
		}
	}
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int u; cin >> u;
		adj[i].push_back(u);
	}
	cycEnd = cycSt = -1;
	dep[0] = -1;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) dfs(i, 0);
		if (cycSt != -1 and cycEnd != -1) break;
	}
	vector<int> ans;
	while (cycSt != cycEnd) ans.push_back(cycSt), cycSt = par[cycSt];
	ans.push_back(cycEnd);
	reverse(ans.begin(), ans.end());
	cout << (int) ans.size() << "\n";
	for (int u : ans) cout << u << " ";
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
 //   cin >> t;
    while(t--) solve();
}
