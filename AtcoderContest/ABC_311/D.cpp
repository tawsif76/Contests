#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 203;

char ara[N][N];
int vis[N][N], dp[N][N];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int n, m;

bool valid(int r, int c) {
	return r >= 1 and r <= n and c >= 1 and c <= m and vis[r][c] == 0;
}

void bfs(int r, int c) {
	vis[r][c] = 1;
	queue<pair<int, int > > Q;
	Q.push({r, c});
	dp[r][c] = 1;
	while (!Q.empty()) {
		auto [nodeR, nodeC] = Q.front(); Q.pop();
		// cerr << nodeR << " " << nodeC << endl;
		for (int i = 0; i < 4; ++i) {
			int nr = dx[i] + nodeR, nc = dy[i] + nodeC;
			if (ara[nr][nc] == '#' or vis[nr][nc]) continue;
			bool ok = 0;
			while (ara[nr][nc] == '.') {
				dp[nr][nc] = 1;
				nr += dx[i], nc += dy[i];
			}
			nr -= dx[i], nc -= dy[i];
			if (!vis[nr][nc]) {
				Q.push({nr, nc});
				vis[nr][nc] = 1;
			} 
		}
	}
} 

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) cin >> ara[i][j];
	int ans = 0;
	bfs(2, 2);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			ans += (ara[i][j] == '.' and dp[i][j]);
		}
	}
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
 //   cin >> t;
    while(t--) solve();
}
