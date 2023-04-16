// counting occurrences

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> occu(10, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x; // x - 1
        for (int j = 0; j < 10; j++)
            occu[j][i] = occu[j][i-1];
        occu[x-1][i] += 1;
    }
    for (int i = 0; i < Q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << occu[c-1][b] - occu[c-1][a-1] << '\n';
    }
    return 0;
}