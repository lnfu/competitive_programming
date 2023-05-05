#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R, C, Q; cin >> R >> C >> Q;
    string line;
    getline(cin, line);

    vector<vector<int>> board(R, vector<int>(C, -5));
    for (int i = 0; i < R; i++) {
        // getchar();
        getline(cin, line);
        for (int j = 0; j < C; j++) {
            if (line[j] == '$')
                board[i][j] = -2;

            if (line[j] == 'D')
                board[i][j] = -1;

            if (line[j] == '.')
                board[i][j] = 0;
        }
    }

    char mark = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 0) {
                // dfs
                stack<pair<int, int>> st;
                st.push({i, j});
                while (!st.empty()) {
                    int x = st.top().first;
                    int y = st.top().second;
                    st.pop();

                    if (x < 0 || x >= R || y < 0 || y >= C || board[x][y] != 0)
                        continue;
                    
                    board[x][y] = mark;
                    
                    const vector<pair<int, int>> d={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                    
                    for (auto &[dx, dy]: d) {
                        int nx = x + dx, ny = y + dy;
                        if (nx < 0 || nx >= R || ny < 0 || ny >= C || board[nx][ny] != 0)
                            continue;
                        st.push({nx, ny});

                    }
                }
                mark++;
            }
        }
    }

    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // map<pair<char, char>, int> count;
    unordered_map<int, int> count;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == -1) {
                vector<int> room;
                const vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for (auto& [dx, dy] : d) {
                    int x = i + dx;
                    int y = j + dy;

                    if (x >= 0 && x < R && y >= 0 && y < C && board[x][y] != -2 && board[x][y] != -1) {
                        room.push_back(board[x][y]);
                    }
                }

                if (room.size() == 2) {
                    count[room[0] * 4000 + room[1]]++;
                    count[room[1] * 4000 + room[0]]++;
                }
                // count[{temp1, temp2}]++;
                // count[{temp2, temp1}]++;
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;
        int t1 = board[si][sj];
        int t2 = board[di][dj];
        if (board[si][sj] == board[di][dj])
            cout << "-1" << ' ';
        else
            cout << count[board[si][sj]*4000 + board[di][dj]] << ' ';
    }
    cout << endl;

    return 0;
}