#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 2e5 + 5;
vector<int> adj[N];
int vis[N], leaf[N];

void dfs(int node) {
  vis[node] = 1;
  if ((int) adj[node].size() == 1 and node != 1) {
    leaf[node] = 1;
  }
  for (auto u : adj[node]) {
    if (!vis[u]) dfs(u), leaf[node] += leaf[u]; 
  }
}

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) adj[i].clear(), leaf[i] = 0, vis[i] = 0;
  for (int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);

  int q; cin >> q;
  while (q--) {
    int u, v; cin >> u >> v;
    cout << 1LL * leaf[u] * leaf[v] << "\n";
  }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
