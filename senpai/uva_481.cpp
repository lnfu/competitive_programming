// https://yuihuang.com/dp-lis/
// Robinson–Schensted–Knuth Algorithm
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> arr;

	int n;
	while (cin >> n) {
		arr.push_back(n);
	}

	n = arr.size();

	vector<int> v;
	vector<int> dp(n, 1);
	int L = 0;
	for (int i = 0; i < n; ++i) {
		auto iter = lower_bound(v.begin(), v.end(), arr[i]);
		if (iter == v.end()) {
			v.push_back(arr[i]);
			dp[i] = v.size();
			L++;
		}
		else {
			*iter = arr[i];
			dp[i] = iter - v.begin() + 1;
		}

	}

	vector<int> res;
	cout << L << '\n';
	cout << "-\n";
	for (int i = n - 1; L > 0 && i >= 0; --i) {
		if (dp[i] == L) {
			res.push_back(arr[i]);
			L--;
		}
	}
	for (int i = res.size() - 1; i >= 0; --i)
		cout << res[i] << '\n';

	return 0;
}