#include <bits/stdc++.h>

using namespace std;

vector<int> dx = {1, 1,  1,  0, -1, -1, -1, 0};
vector<int> dy = {1, 0, -1, -1, -1,  0,  1, 1};

void dfs(vector<vector<char>>& board, int i, int j) {
    int n = board.size();
    int m = board[0].size();

    if (i < 0 || i >= n || j < 0 || j >= m || (board[i][j] != 'M' && board[i][j] != '#'))
        return;
    
    if (board[i][j] == 'M') {
        board[i][j] = '*';
        return;
    }

    int temp = 0;
    for (int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x < 0 || x >= n || y < 0 || y >= m)
            continue;
        
        if (board[x][y] == 'M')
            temp++;
    }

    if (temp > 0) {
        board[i][j] = '0' + temp;
        return;
    }

    board[i][j] = '.';
    for (int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        
        dfs(board, x, y);
    }
}

int main() {
    int n, m, k; cin >> n >> m >> k;

    vector<vector<char>> board(n, vector<char>(m, '#'));
    for (int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        board[r-1][c-1] = 'M';
    }

    int r, c; cin >> r >> c;
    dfs(board, r-1, c-1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'M') 
                cout << '#';
            else
                cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}