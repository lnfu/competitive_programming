#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans = 0;
    long long cur = 5;
    while (cur <= n) {
        long long temp = cur;
        for (long long i = temp; i <= n; i += temp) {
            ans++;
        }
        cur *= 5;
    }
    cout << ans;
    return 0;
}