#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<char>>& landMap, int i, int j, set<char>& record) {
    int M = landMap.size();
    int N = landMap[0].size();

    if (i < 0 || i >= M || j < 0 || j >= N || landMap[i][j] < '1' || landMap[i][j] > '9')
        return 0;
    
    record.insert(landMap[i][j]);
    landMap[i][j] = 'v';

    return 1 +
           dfs(landMap, i-1, j, record) + 
           dfs(landMap, i+1, j, record) + 
           dfs(landMap, i, j-1, record) + 
           dfs(landMap, i, j+1, record);
}

int main() {
    int M, N; cin >> M >> N;
    vector<vector<char>> landMap(M, vector<char>(N, ' '));

    for (int i = 0; i < M; i++) {
        getchar();
        for (int j = 0; j < N; j++) {
            landMap[i][j] = getchar();
        }
    }

    int ans = -1;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (landMap[i][j] >= '1' && landMap[i][j] <= '9') {
                set<char> record;
                int temp = dfs(landMap, i, j, record);
                if (record.size() == 9) {
                    ans = max(ans, temp);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}