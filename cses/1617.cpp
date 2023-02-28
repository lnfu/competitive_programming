#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans = 1;
    while (n--) {
        ans = ans * 2 % 1000000007;
    }
    cout << ans;
    return 0;
}