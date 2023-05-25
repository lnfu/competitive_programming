#include <bits/stdc++.h>

using namespace std;

void backtrack(int n, set<pair<int, int>>& forbid,
	vector<bool>& visited, int cnt, int now, int& ans) {
	if (cnt == n) {
		if (forbid.find({0, now}) == forbid.end()) {
			ans = (ans + 1) % 9901;
		}
		return;
	}


	for (int i = 0; i < n; ++i) {
		if (visited[i] == false && forbid.find({now, i}) == forbid.end()) {
			visited[i] = true;
			backtrack(n, forbid, visited, cnt+1, i, ans);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	for (int time = 0; time < t; ++time) {
		int n, k; cin >> n >> k;
		set<pair<int, int>> forbid;
		vector<bool> visited(n, false);
		int ans = 0;
		for (int i = 0; i < k; ++i) {
			int p1, p2; cin >> p1 >> p2;
			forbid.insert({p1 - 1, p2 - 1});
			forbid.insert({p2 - 1, p1 - 1});
		}

		visited[0] = true; // not useful
		backtrack(n, forbid, visited, 1, 0, ans);
		cout << "Case #" << time + 1 << ": " << ans / 2 << '\n';
	}
	return 0;
}


// 1 3 5 2 4
// 1 2 3 4
// 1 4 2 3
// 1 3 2 4