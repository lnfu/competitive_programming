// 線段數練習（二）
// 我太難了
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define INF 100005
#define x first
#define y second
typedef pair<int, int> pii;

struct node {
	pii M;
	pii L;
	pii R;
};

int a[INF];
node seg[INF << 2];

void clear() {
	for (int i = 0; i < INF; ++i) {
		a[i] = 0;
	}

	for (int i = 0; i < (INF << 4); ++i) {
		seg[i].M.x = seg[i].M.y = 0;
		seg[i].L.x = seg[i].L.y = 0;
		seg[i].R.x = seg[i].R.y = 0;
	}
}

inline node combine(node l, node r) {
	node p;
	if (l.L.x == r.R.x) {
		p.M.x = p.L.x = p.R.x = l.L.x;
		p.M.y = p.L.y = p.R.y = l.L.y + r.R.y;
		return p;
	}

	p.L.x = l.L.x;
	if (l.L.x == r.L.x)
		p.L.y = l.L.y + r.L.y;
	else
		p.L.y = l.L.y;

	p.R.x = r.R.x;
	if (r.R.x == l.R.x)
		p.R.y = r.R.y + l.R.y;
	else
		p.R.y = r.R.y;


	// M 的三種可能
	// 1. 
	p.M = l.M;
	// 2.
	if (r.M.y > p.M.y)
		p.M = r.M;
	// 3. 橫跨兩邊（包含前兩種）
	if (l.R.x == r.L.x) {
		pii temp;
		temp.x = l.R.x;
		temp.y = l.R.y + r.L.y;
		if (temp.y > p.M.y)
			p.M = temp;
	}

	return p;
}

void build(int idx, int il, int ir) {
	if (il == ir) {
		seg[idx].M.x = seg[idx].L.x = seg[idx].R.x = a[il];
		seg[idx].M.y = seg[idx].L.y = seg[idx].R.y = 1;
		return ;
	}

	int mid = (il + ir) / 2;
	build(idx * 2 + 1, il, mid);
	build(idx * 2 + 2, mid + 1, ir);

	seg[idx] = combine(
		seg[idx * 2 + 1],
		seg[idx * 2 + 2]
	);
}

node query(int idx, int il, int ir, int ql, int qr) {
	if (ql <= il && ir <= qr)
		return seg[idx];

	int mid = (il + ir) / 2;
	if (qr <= mid)
		return query(idx * 2 + 1, il, mid, ql, qr);
	if (ql > mid)
		return query(idx * 2 + 2, mid + 1, ir, ql, qr);

	return combine(
		query(idx * 2 + 1, il, mid, ql, qr),
		query(idx * 2 + 2, mid + 1, ir, ql, qr)
	);

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n) {
		if (n == 0)
			return 0;
		int q; cin >> q;

		clear();
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		build(0, 0, n - 1);

		for (int i = 0; i < q; ++i) {
			int x, y; cin >> x >> y;
			cout << query(0, 0, n - 1, x - 1, y - 1).M.y << '\n';
		}

	}
	return 0;
}