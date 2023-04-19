#include <bits/stdc++.h>

using namespace std;

int main() {
    int M; cin >> M;

    int a, b; cin >> a >> b;

    vector<int> numberGroup(M, 0);
    for (int i = 0; i < M; i++) {
        cin >> numberGroup[i];
    }

    auto ta = lower_bound(numberGroup.begin(), numberGroup.end(), a) - numberGroup.begin();
    auto tb = lower_bound(numberGroup.begin(), numberGroup.end(), b + 1) - numberGroup.begin() - 1;
    if (ta > tb) {
        cout << "-1 -1" << endl;
        return 0;
    }

    cout << ta << ' ' << tb << endl;

    return 0;
}