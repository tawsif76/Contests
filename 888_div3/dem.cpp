#include <bits/stdc++.h>

using namespace std;
using LL = long long;

// CPP Program to find maximum XOR value of a pair
#include <bits/stdc++.h>
using namespace std;

// Utility function to check number of elements
// having set msb as of pattern
int checkBit(int pattern, int arr[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if ((pattern & arr[i]) == pattern)
			count++;
	return count;
}

// Function for finding maximum and value pair
int maxAND(int arr[], int n)
{
	int res = 0, count;

	// iterate over total of 32bits from msb to lsb
	for (int bit = 31; bit >= 0; bit--) {
		// find the count of element having same pattern as
		// obtained by adding bits on every iteration.
		count = checkBit(res | (1 << bit), arr, n);

		// if count >= 2 set particular bit in result
		if (count >= 2)
			res = res | (1 << bit); // this is the pattern
									// we continued
	}

	return res;
}

void solve() {
	int n, k; cin >> n >> k;
	int arr[n + 1];
	for (int i = 0; i < n; ++i) cin >> arr[i];
	cout << maxAND(arr, n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
