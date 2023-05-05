#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N; // 1 ~ 1000
    vector<vector<int>> matrix(N, vector<int>(N, -1));
    for (int i = 0; i < N*N; i++) {
        int temp;
        cin >> temp;
        matrix[i/N][i%N] = temp;
    }
    return 0;
}