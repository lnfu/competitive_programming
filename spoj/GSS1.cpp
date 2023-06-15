// 線段數練習（一）
// 全部使用 zero index
#include <bits/stdc++.h>
#define int long long

struct node {
	int sum;
	int left;  // prefix sum 最大值
	int right; // suffix sum 最大值
	int maxSum;
};

const int N = 50001;
int a[N << 4]; // 4 sub 
node seg[N << 4];

using namespace std;

int getMid(int a, int b) {
	return a + (b - a) / 2;
}

node emptyNode() {
	node p;
	p.sum = p.maxSum = p.left = p.right = 0;
	return p;
}

void fill(int idx) {
	int l = idx * 2 + 1;
	int r = idx * 2 + 2;

	seg[idx].sum = seg[l].sum + seg[r].sum;
	seg[idx].left = max(seg[l].left, seg[l].sum + seg[r].left);
	seg[idx].right = max(seg[r].right, seg[r].sum + seg[l].right);
	seg[idx].maxSum = max(
		max(seg[l].maxSum, seg[r].maxSum),
		seg[l].right + seg[r].left
	);
}

void build(int from, int to, int idx) {
	if (from == to) {
		// leaf?
		seg[idx].sum = a[from];
		seg[idx].maxSum = a[from];
		seg[idx].left = a[from];
		seg[idx].right = a[from];
		return;
	}

	int mid = getMid(from, to);
	build(from, mid, idx * 2 + 1);
	build(mid + 1, to, idx * 2 + 2);
	fill(idx);
}

node combine(node l, node r) {
	node p;
	p.sum = l.sum + r.sum;
	p.left = max(l.left, l.sum + r.left);
	p.right = max(r.right, r.sum + l.right);
	p.maxSum = max(
		max(l.maxSum, r.maxSum),
		l.right + r.left
	);
	return p;
}

node query(int idx, int from, int to, int l, int r) {
	if (r < from || l > to)
		return emptyNode();

	if (from >= l && to <= r)
		return seg[idx];

	int mid = getMid(from, to);
	if (r <= mid)
		return query(idx * 2 + 1, from, mid, l, r);
	else if (l > mid)
		return query(idx * 2 + 2, mid + 1, to, l, r);
	else
		return combine(
			query(idx * 2 + 1, from, mid, l, r),
			query(idx * 2 + 2, mid + 1, to, l, r)
		);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	build(0, n - 1, 0); // from 0 to n - 1

	int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		cout << query(0, 0, n - 1, x - 1, y - 1).maxSum << '\n';
	}



	return 0;
}