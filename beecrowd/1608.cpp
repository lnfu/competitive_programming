#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

typedef pair<int, int> pii;

int main() {
	int T; cin >> T;
	while (T--) {
		int D, I, B; cin >>D >> I >> B;
		vector<int> prices(I);
		for (int i = 0; i < I; ++i) {
			cin >> prices[i];
		}

		int mn = INF;
		for (int i = 0; i < B; ++i) {
			int Q; cin >> Q;
			int total = 0;
			for (int j = 0; j < Q; ++j) {
				int id, cnt; cin >> id >> cnt;
				total += (cnt * prices[id]);
			}
			if (total < mn)
				mn = total;
		}
		cout << D / mn << endl;


	}
	return 0;
}