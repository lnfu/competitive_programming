#include <bits/stdc++.h>

using namespace std;

bool valid(const int i, const int j,
        const int maxI, const int maxJ,
        set<pair<int, int>> block) {
    if (i <= 0 || i > maxI)
        return false;
    if (j <= 0 || j > maxJ)
        return false;
    if (block.count({i, j}) > 0)
        return false;
    return true;
}

void dfs(int i, int j,
        const int maxI, const int maxJ,
        int& answer,
        const set<pair<int, int>>& block) {
    if (i == maxI && j == maxJ) {
        answer++;
        return;
    } else if (i == maxI) {
        return;
    } else if (j == maxJ) {
        return;
    }

    if (valid(i + 2, j + 1, maxI, maxJ, block))
        dfs(i + 2, j + 1, maxI, maxJ, answer, block);
    
    if (valid(i + 1, j + 2, maxI, maxJ, block))
        dfs(i + 1, j + 2, maxI, maxJ, answer, block);
}

int main() {
    int N;
    cin >> N;
    for (int t = 0; t < N; t++) {
        int H, W, R;
        int answer = 0;
        set<pair<int, int>> block;
        cin >> H >> W >> R;
        for (int i = 0; i < R; i++) {
            int r, c;
            cin >> r >> c;
            block.insert({r, c});
        }
        dfs(1, 1, H, W, answer, block);
        cout << "Case #" << t + 1 << ": " << answer << '\n';
    }
    return 0;
}
