#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> diff;
    for (int i = 0; i < n; i++) {
        int time;
        cin >> time;
        diff[time]++;
        diff[time+1000]--;
    }
    int acc = 0;
    int max = 0;
    for (const auto& [key, value] : diff) {
        acc += value;
        if (acc > max)
            max = acc;
    }
    
    cout << (max + k - 1) / k << endl;

    return 0;
}