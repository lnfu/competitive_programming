#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> heights(1000001, 0);
    int ctr = 0;
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        if (heights[h] == 0) {
            ctr++;
            heights[h]++;
        }
        
        heights[h]--;
        heights[h-1]++;
    }
    cout << ctr << endl;
    return 0;
}