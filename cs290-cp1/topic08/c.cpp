#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<char>>& board, int i, int j, int distI, int distJ) {
}

int main() {
    int R, C, Q; cin >> R >> C >> Q;

    vector<vector<char>> board(R, vector<char>(C, ' '));
    for (int i = 0; i < R; i++) {
        getchar();
        for (int j = 0; j < C; j++) {
            board[i][j] = getchar();
        }
    }

    for (int i = 0; i < Q; i++) {
        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;
    }
    cout << endl;

    return 0;
}