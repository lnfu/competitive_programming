#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, T;
    cin >> N >> M >> T;
    vector<vector<pair<int, int>>> adj(N);

    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    int s, t;
    cin >> s >> t;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        // spider
    }

    return 0;
}