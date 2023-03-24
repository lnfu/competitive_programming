#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
    public:
        vector<int> p;
        DisjointSet(int n) {
            for (int i = 0; i < n; i++)
                p.push_back(i);
        }
        int Find(int x) {
            if (p[x] == x)
                return x;
            return p[x] = Find(p[x]);
        }
        void Union(int x, int y) {
            int g1 = Find(x);
            int g2 = Find(y);
            if (g1 != g2)
                p[g2] = g1;
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    DisjointSet ds(N);
    while (Q--) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == '?') {
            cout << (ds.Find(a) == ds.Find(b) ? "yes" : "no") << '\n';
        }

        if (op == '=') {
            ds.Union(a, b);
        }
    }
    return 0;
}