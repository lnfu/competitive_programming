#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool valid(int i, int j, int x, int y, int dis, vector<vector<int>>& board, vector<vector<bool>>& visited) {
    int n = board.size();
    int m = board[0].size();
    if (i < 0 || i >= n)
        return false;
    if (j < 0 || j >= m)
        return false;
    if (visited[i][j])
        return false;
    if (abs(i - x) + abs(j - y) > dis)
        return false;
    return true;
}

void dfs(int i, int j, int x, int y, int dis, vector<vector<int>>& board, vector<vector<bool>>& visited) {
    board[i][j] = 1;
    visited[i][j] = true;
    if (valid(i - 1, j - 1, x, y, dis, board, visited))
        dfs(i - 1, j - 1, x, y, dis, board, visited);
    if (valid(i - 1, j, x, y, dis, board, visited))
        dfs(i - 1, j, x, y, dis, board, visited);
    if (valid(i - 1, j + 1, x, y, dis, board, visited))
        dfs(i - 1, j + 1, x, y, dis, board, visited);
    if (valid(i, j + 1, x, y, dis, board, visited))
        dfs(i, j + 1, x, y, dis, board, visited);
    if (valid(i + 1, j + 1, x, y, dis, board, visited))
        dfs(i + 1, j + 1, x, y, dis, board, visited);
    if (valid(i + 1, j, x, y, dis, board, visited))
        dfs(i + 1, j, x, y, dis, board, visited);
    if (valid(i + 1, j - 1, x, y, dis, board, visited))
        dfs(i + 1, j - 1, x, y, dis, board, visited);
    if (valid(i, j - 1, x, y, dis, board, visited))
        dfs(i, j - 1, x, y, dis, board, visited);
}
int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> board(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char temp;
            cin >> temp;
            if (temp == '.') {
                board[i][j] = 1;
            } else if (temp == '#') {
                if (board[i][j] == 0)
                    board[i][j] = 2;
            } else {
                vector<vector<bool>> visited(R, vector<bool>(C, false));
                dfs(i, j, i, j, temp - '0', board, visited);
            }
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 1)
                cout << '.';
            else
                cout << '#';
        }
        cout << '\n';
    }
    return 0;
}