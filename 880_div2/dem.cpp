#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int a, b, c; cin >> a >> b >> c;
	int valA = 1, valB = 1, k = 1;
	for (int i = 1; i < a; ++i) valA *= 10;
	for (int i = 1; i < b; ++i) valB *= 10;
	cerr << valA << " " << valB << endl;
	for (int i = valA; i <= 9; ++i) {
		int tot = 0;
		for (int j = valB; j <= 9; ++j) {
			int sum = i + j, cnt = 0;
			while (sum) cnt++, sum /= 10;
			if (cnt == c) {
				tot++;
				//k++;
				cerr <<  i << " " << j << ' ' << i + j << endl; 
			}
		}
		cerr << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->"<< tot << "\n";
	}
	cout << k << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
