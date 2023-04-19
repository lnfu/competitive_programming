#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;

    vector<pair<int, int>> atks(N, {0, 0});
    for (int i = 0; i < N; i++)
        cin >> atks[i].first >> atks[i].second;
    int H; cin >> H;

    unsigned long long target = H* 10000;
    unsigned long long l = 0;
    unsigned long long r = target;

    while (r - l > 1) {
        unsigned long long middle = l + (r - l)/2;
        unsigned long long now = 0;

        for (const auto& atk : atks) {
            unsigned long long more = (atk.second*10000 - middle) * 2000000 / (2000000 + middle);
            if (more < middle)
                continue;
            
            now += atk.first * (more - middle);
        }

        if (now > target) {
            l = middle;
        } else {
            r = middle;
        }
    }

    cout << r << ' ' << l << endl;

    return 0;
}