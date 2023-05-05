#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> mountainGroup;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        mountainGroup.push_back(temp);
    }

    int highest = mountainGroup[0];
    int lowest = mountainGroup[0];
    int maxJump = 0;

    for (const auto& mountain : mountainGroup) {
        lowest = min(mountain, lowest);

        if (mountain > highest) {
            // cal
            maxJump = max(highest - lowest, maxJump);
            // reset
            highest = mountain;
            lowest = mountain;
        } else {
            maxJump = max(mountain - lowest, maxJump);
        }
    }

    cout << maxJump << endl;

    return 0;
}