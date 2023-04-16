#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        cout << "Case #" << i + 1 << ": ";

        unsigned long long N; cin >> N;

        unsigned long long group = -1;
        unsigned long long diff = -1;
        for (unsigned long long j = 1; j <= ULLONG_MAX; j++) {
            if (13 * j * (j-1) < N && 13 * j * (j+1) >= N) {
                group = j;
                diff = N - (13 * j * (j-1));
                break;
            }
        }
        printf("%c\n", 'A' + (int)((diff + group - 1) / group - 1));
    }
    return 0;
}