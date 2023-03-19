#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> arr;
        vector<int> prefix(n, 0);
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            arr.push_back(temp);

            prefix[i] = (i == 0) ? temp : prefix[i-1] + temp;
        }
        for (int i = 0; i < q; i++) {
            int l, r, k;
            cin >> l >> r >> k;
            int ans = 0;
            if (l - 2 >= 0)
                ans += prefix[l - 2];
            ans += prefix[n-1] - prefix[r-1];
            ans += k * (r - l + 1);
            if (ans % 2 == 0)
                cout << "NO\n";
            else
                cout << "YES\n";
            
        }
    }
    return 0;
}