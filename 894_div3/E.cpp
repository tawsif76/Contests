#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	LL n, m, d; cin >> n >> m >> d;
	LL ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	priority_queue<LL> pq;
	LL sum = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (ara[i] < 0) continue;
		if ((int) pq.size() < m) {
			sum += ara[i];
			pq.push(-ara[i]);
			ans = max(ans, sum - (d * i));
			continue;
		}
		if ((int) pq.size() >= m and -pq.top() < ara[i]) {
			sum -= -pq.top();
			pq.pop();
			pq.push(-ara[i]);
			sum += ara[i];
		}
		ans = max(ans, sum - (d * i));
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