#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> v(m);
	vector<int> w(m);
	// vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	vector<int> dp(n + 1, 0);
	for (int i = 0; i < m; ++i) {
		cin >> v[i];
		cin >> w[i];
	}

	for (int i = 0; i < m; ++i) {
		for (int j = n; j >= v[i]; --j) {
			dp[j] = max(dp[j], dp[j-v[i]] + v[i] * w[i]);
		}
	}
	cout << dp[n] << '\n';
	return 0;
}
