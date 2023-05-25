#include <bits/stdc++.h>

using namespace std;

int main() {
	int C, P, X, L; cin >> C >> P >> X >> L;
	vector<vector<int>> adj(C+1);
	vector<int> linkTotal(C+1, 0);
	vector<int> linkStay(C+1, 0);
	for (int i = 0; i < P; ++i) {
		int A, B; cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);

		linkTotal[A]++;
		linkTotal[B]++;

		linkStay[A]++;
		linkStay[B]++;
	}

	deque<int> q;
	q.push_back(L);

	vector<bool> leave(C+1, false);
	leave[L] = true;
	for (auto v : adj[L]) {
		linkStay[v]--;
		q.push_back(v);
	}

	// bfs
	while (q.size() > 0) {
		int curr = q.front(); q.pop_front();

		if (leave[curr])
			continue;

		if (linkStay[curr] <= linkTotal[curr] / 2) {
			leave[curr] = true;
			for (auto v : adj[curr]) {
				linkStay[v]--;
				q.push_back(v);
			}
		}

	}



	if (leave[X])
		cout << "leave\n";
	else
		cout << "stay\n";

	return 0;
}