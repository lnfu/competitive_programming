#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input2.txt", "r", stdin);
#endif
    int N, M, P;
    cin >> N >> M >> P;
    vector<int> c_group;
    vector<int> d_group;
    vector<float> total_group;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        c_group.push_back(temp);
    }
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        d_group.push_back(temp);
    }
    for (const auto& c : c_group) {
        for (const auto& d : d_group) {
            total_group.push_back((float)c / (float)d);
        }
    }
    float prev = -1.0;
    sort(total_group.begin(), total_group.end(), greater<float>());
    for (const auto& total : total_group) {
        if (prev != -1.0 && 100.0 * prev / total - 100.0 > (float)P) {
            cout << "Time to change gears!" << endl;
            return 0;
        }
        prev = total;
    }
    cout << "Ride on!" << endl;
    return 0;
}