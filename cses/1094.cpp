#include <iostream>

using namespace std;

int main() {
    int n, prev = 0;
    long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int curr;
        cin >> curr;

        if (prev != 0 && curr < prev)
            ans += (prev - curr);
        else 
            prev = curr;
    }
    cout << ans;

    return 0;
}