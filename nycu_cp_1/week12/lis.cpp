#include <bits/stdc++.h>

using namespace std;

#define INF 10000
#define all(x) (x).begin(), (x).end()

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> seq(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> seq[i];
	}
	vector<int> mem(n + 1, INF); // 長度是 k 的
	mem[0] = -INF;

	for (int i = 0; i < n; ++i) {
		auto iter = lower_bound(all(mem), seq[i]);
		*(iter) = seq[i];
	}
	for (int i = 0; i <= n; ++i) {
		cout << mem[i] << ' ';
	}
	cout << endl;
	return 0;
}