#include <bits/stdc++.h>

using namespace std;

const vector<vector<int>> left_up = {
    {0, 0},
    {0, 1},
    {0, 2},
    {1, 0},
    {1, 1},
    {1, 2},
    {2, 0},
    {2, 1},
    {2, 2}
};
void rotate(vector<vector<int>>& square, int type) {
    // type = 0 ~ 8
    int ti = left_up[type][0];
    int tj = left_up[type][1];
    int temp = square[ti][tj];
    square[ti][tj] = square[ti+1][tj];
    square[ti+1][tj] = square[ti+1][tj+1];
    square[ti+1][tj+1] = square[ti][tj+1];
    square[ti][tj+1] = temp;
}
bool isAries(vector<vector<int>>& square) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (square[i][j] != i*4 + j + 1)
                return false;
        }
    }
    return true;
}

int dfs(vector<vector<int>>& square) {
    if (isAries(square))
        return 0;
    ;

    return 1 +
           min();
}

int main() {
    int T; cin >> T;

    while (T--) {
        vector<vector<int>> origin(4, vector<int>(4, 0));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> origin[i][j];
            }
        }
        rotate(origin, 1);
        for (int i = 0 ;i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << origin[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << isAries(origin) << endl;;
    }

    return 0;
}