#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int l = 0; // cannot
    int r = (n + k - 1) / k; // can
    vector<int> request;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        request.push_back(temp);
    }
    while (r - l > 1) {
        int mid = (r + l) / 2;
        vector<int> status(mid*k, -1000);
        bool midValid = true;
        for (const auto& r : request) {
            bool work = false;
            for (int i = 0; i < mid*k; i++) {
                if (r - status[i] >= 1000) {
                    status[i] = r;
                    work = true;
                    break;
                }
            }
            if (!work) {
                midValid = false;
                break;
            }
        }
        if (midValid)
            r = mid;
        else
            l = mid;
    }
    cout << r;
    return 0;
}