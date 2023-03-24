#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
    public:
        vector<int> p;
        DisjointSet(int n) {
            for (int i = 0; i <= n; i++)
                p.push_back(i);
        }
        int Find(int x) {
            if (p[x] == x)
                return x;
            return p[x] = Find(p[x]);
        }
        void Union(int x, int y) {
            int g1 = Find(p[x]);
            int g2 = Find(p[y]);
            if (g1 != g2) {
                if (g1 == 1)
                    p[g2] = 1;
                else if (g2 == 1)
                    p[g1] = 1;
                else
                    p[g2] = g1;
            }
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    DisjointSet ds(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ds.Union(a, b);
    }
    bool connected = true;
    for (int i = 1; i <= N; i++) {
        if (ds.Find(i) != 1) {
            connected = false;
            cout << i << '\n';
        }
    }
    if (connected)
        cout << "Connected" << endl;
    return 0;
}
