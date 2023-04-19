#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long N; cin >> N;

    unsigned long long l = 0;
    unsigned long long r = 1e9;
    // int T = 5;
    while (true) {
        unsigned long long middle = l + (r - l) / 2;
        unsigned long long temp1 = middle * middle;
        unsigned long long temp2 = (middle+1) * (middle+1);
        // cout << temp1 << endl;
        // cout << temp2 << endl;
        if (temp1 <= N && N < temp2) {
            cout << middle << endl;
            break;
        } else if (temp1 > N) {
            r = middle;
        } else if (temp2 <= N) {
            l = middle;
        }
    }

    return 0;
}