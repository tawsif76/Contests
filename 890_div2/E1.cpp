#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 5005;

vector<int> adj[N];
int sub[N];
LL ans;

void dfs(int node) {
  sub[node] = 1;
  vector<int> child;
  child.push_back(0);
  for (int u : adj[node]) {
    if (u ^ node) {
      dfs(u);
      sub[node] += sub[u];
      child.push_back(sub[u]);
    }
  }
  int sum = (sub[node] - 1) / 2, hi = 0;
  bool dp[sum + 1]{};
  dp[0] = 1;
  for (int i = 1; i < (int) child.size(); ++i) {
    for (int s = sum; s >= 0; --s) {
      if (s - child[i] >= 0) dp[s] |= dp[s - child[i]];
    }
  }
  for (int i  = 1; i <= sum; ++i) if (dp[i]) hi = i;
  ans += 1LL * (hi * ((sub[node] - 1) - hi));
}

void solve() {
  int n; cin >> n;
  for (int i = 2; i <= n; ++i) {
    int u; cin >> u;
    adj[u].push_back(i);
  }
  ans = 0;
  dfs(1);
  cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    // cin >> t;
    while(t--) solve();
}