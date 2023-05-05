#include <cstdio>

const int N = 1e5;
int n;
int t[2 * N];

// tips: t[i] and t[i^1] are sibling

// example: n = 16

void build() {
	for (int i = n - 1; i > 0; --i) {
		// e.g., t[15] = t[30] + t[31]
		t[i] = t[i<<1] + t[i<<1 | 1];
	}
}


void modify(int p, int value) {
	for (t[p += n] = value; p > 1; p >>= 1) {
		t[p>>1] = t[p] + t[p ^ 1];
	}
}

int query(int l, int r) {
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) // l is odd
			res += t[l++];
		if (r & 1) // r is odd
			res += t[--r];
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) 
		scanf("%d", t + n + i);
	build();
	modify(0, 1);
	printf("%d\n", query(3, 11));
	return 0;
}