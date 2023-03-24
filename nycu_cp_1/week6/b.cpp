#include <bits/stdc++.h>

using namespace std;

bool valid(int i, int j, vector<vector<int>>& dishes) {
    int m = dishes.size();
    int n = dishes[0].size();
    if (i < 0 || i >= m)
        return false;
    if (j < 0 || j >= n)
        return false;
    return dishes[i][j] == 1;
}
void backtrack(int i, int j, vector<vector<int>>& dishes) {
    dishes[i][j] = 2;
    if (valid(i, j + 1, dishes))
        backtrack(i, j + 1, dishes);
    else if (valid(i + 1, j + 1, dishes))
        backtrack(i + 1, j + 1, dishes);
    else if (valid(i + 1, j, dishes))
        backtrack(i + 1, j, dishes);
    else if (valid(i + 1, j - 1, dishes))
        backtrack(i + 1, j - 1, dishes);
    else if (valid(i, j - 1, dishes))
        backtrack(i, j - 1, dishes);
    else if (valid(i - 1, j - 1, dishes))
        backtrack(i - 1, j - 1, dishes);
    else if (valid(i - 1, j, dishes))
        backtrack(i - 1, j, dishes);
    else if (valid(i - 1, j + 1, dishes))
        backtrack(i - 1, j + 1, dishes);
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dishes(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char temp;
            cin >> temp;
            if (temp == '#')
                dishes[i][j] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dishes[i][j] == 1) {
                ans++;
                backtrack(i, j, dishes);
            }
        }
    }
    cout << ans << endl;

    return 0;
}